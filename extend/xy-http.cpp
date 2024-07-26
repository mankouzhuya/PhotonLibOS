//
// Created by jun on 2024/7/25.
//

#include "photon/extend/xy-http.h"
#include<algorithm>
#include <sstream>
#include "photon/extend/magic_enum/magic_enum.hpp"
#include "photon/thread/thread.h"
#include <photon/common/alog-stdstring.h>
#include <urlmatch.h>

namespace zyio{
    namespace http{

        BizLogicProxy::BizLogicProxy(httpPHandler logic):logic(std::move(logic)){

        }

        void BizLogicProxy::executeOnce(photon::net::http::Request &request, photon::net::http::Response &response) {
            if (hasExecute) {
                return;
            }
            logic(request, response);
            this->hasExecute = true;
        }

        HttpFilter::HttpFilter(int order):order(order) {

        }

        HttpFilterChain::HttpFilterChain(std::string pattern,photon::net::http::Verb method) : pattern(pattern),method(method){
            chain = new std::vector<HttpFilter*>();
        }
        HttpFilterChain::~HttpFilterChain() {
            delete chain;
        }

        void HttpFilterChain::addFilter(zyio::http::HttpFilter *filter) {
            chain->push_back(filter);
            std::sort(chain->begin(), chain->end(), [](auto t1, auto t2) -> bool {
                return t1->getOrder() > t2->getOrder();
            });
        }

        bool HttpFilterChain::preHandle(photon::net::http::Request &req,
                                        photon::net::http::Response &resp) {
            bool result = true;
            for (const auto &item: *chain) {
                if (!item->preHandle(req, resp)) {
                    result = false;
                    break;
                }
            }
            return result;
        }

        void HttpFilterChain::postHandle(BizLogicProxy &logicProxy, photon::net::http::Request &req,
                                         photon::net::http::Response &resp) {
            for (const auto &item: *chain) {
               item->postHandle(logicProxy, req, resp);
            }
        }

        void HttpFilterChain::afterHandle(photon::net::http::Request &req,
                                          photon::net::http::Response &resp) {
            for (const auto &item: *chain) {
                item->afterHandle(req, resp);
            }
        }


        XyHttpServer::~XyHttpServer() noexcept {
            status = ServerStatus::stopping;
            for (const auto& it: connections) {
                it->sock->shutdown(ShutdownHow::ReadWrite);
            }
            while (workers != 0) {
                photon::thread_usleep(50 * 1000);
            }
        }

//        int not_found_handler(photon::net::http::Request& req, photon::net::http::Response& resp) {
//            resp.set_result(404);
//            resp.headers.content_length(0);
//            return 0;
//        }
//
//        int error_handler(photon::net::http::Request& req, photon::net::http::Response& resp) {
//            resp.set_result(500);
//            resp.headers.content_length(0);
//            return 0;
//        }

        photon::net::ISocketServer::Handler XyHttpServer::getConnectionHandler() {
            return {this, &XyHttpServer::handleConnection};
        }




        int XyHttpServer::handleConnection(photon::net::ISocketStream *sock) {
            workers++;
            DEFER(workers--);
            SockItem sock_item(sock);
            connections.push_back(&sock_item);
            DEFER(connections.erase(&sock_item));

            char req_buf[64*1024];
            char resp_buf[64*1024];
            photon::net::http::Request req(req_buf, 64*1024-1);
            photon::net::http::Response resp(resp_buf, 64*1024-1);

            while (status == ServerStatus::running) {
                req.reset(sock, false);

                auto rec_ret = req.receive_header();
                if (rec_ret < 0) {
                    LOG_ERROR_RETURN(0, -1, "read request header failed");
                }
                if (rec_ret == 1) {
                    LOG_DEBUG("exit");
                    return -1;
                }

                LOG_DEBUG("Request Accepted", VALUE(req.verb()), VALUE(req.target()), VALUE(req.headers["Authorization"]));

                resp.reset(sock, false);
                resp.keep_alive(req.keep_alive());

                auto logic = findHttpPHandler(req);
                //404
                if (logic == nullptr) {
                    //write 404
                    break;
                }
                //wrap logic
                BizLogicProxy logicProxy(logic);
                HttpFilterChain* httpFilterChain = matchFilterChain(req);
                //no filter chain
                if (httpFilterChain == nullptr) {
                    logicProxy.executeOnce(req, resp);
                    break;
                }
                //pre
                bool res = httpFilterChain->preHandle(req,resp);
                if (!res) {
                    //filter stop handle
                    break;
                }
                //post
                httpFilterChain->postHandle(logicProxy, req, resp);
                httpFilterChain->afterHandle(req, resp);

                if (resp.send() < 0) {
                    LOG_ERROR_RETURN(0, -1, "failed to send");
                }

                if (!resp.keep_alive())
                    break;

                if (req.skip_remain() < 0)
                    break;
            }
            return 0;
        }

        std::string genHttpMapKey(std::string url,photon::net::http::Verb method){
            auto verb =  magic_enum::enum_name(method);
            std::stringstream key;
            key << url;
            key << "@";
            key << verb;
            return key.str();
        }

        void XyHttpServer::bindFilterChain(zyio::http::HttpFilterChain *filterChain) {
            std::string key = genHttpMapKey(filterChain->getPattern(),filterChain->getMethod());
            chainContainer.insert({key,filterChain});
        }

        void XyHttpServer::addHandler(httpPHandler handler,std::string pattern,photon::net::http::Verb method){
            std::string key = genHttpMapKey(pattern,method);
            handlerContainer.insert({key,handler});
        }

        HttpFilterChain* XyHttpServer::matchFilterChain(photon::net::http::Request &req) {
            auto key = genHttpMapKey(std::string(req.target()) ,req.verb());
            for (auto m: chainContainer) {
                if (url_simplematch(m.first.c_str(), key.c_str())) {
                    auto chain = m.second;
                    return chain;
                }
            }
            return nullptr;
        }

        httpPHandler XyHttpServer::findHttpPHandler(photon::net::http::Request &req) {
            auto key = genHttpMapKey(std::string(req.target()) ,req.verb());
            auto value = handlerContainer.find(key);
            if (value != handlerContainer.end()) {
                return value->second;
            }
            return nullptr;
        }


    }
}
