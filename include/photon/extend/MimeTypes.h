#ifndef MIMETYPES_H_
#define MIMETYPES_H_
#include <string.h>

class MimeTypes {
  public:
    static const char* getType(const char * path);
    static const char* getExtension(const char * type, int skip = 0);

//  private:
    struct entry {
      const char* fileExtension;
      const char* mimeType;
      bool isTextType;
    };
    static MimeTypes::entry types[347];
    static int strcmpi(const char *s1, const char *s2);
};


enum ContentType{
    audio_3gpp_3gpp,
    video_jpm_jpm,
    audio_mp3_mp3,
    text_rtf_rtf,
    audio_wave_wav,
    text_xml_xml,
    video_3gpp2_3g2,
    video_3gpp_3gp,
    video_3gpp_3gpp,
    application_pkix_attr_cert_ac,
    audio_adpcm_adp,
    application_postscript_ai,
    image_apng_apng,
    text_cache_manifest_appcache,
    application_pgp_signature_asc,
    application_atom_xml_atom,
    application_atomcat_xml_atomcat,
    application_atomsvc_xml_atomsvc,
    audio_basic_au,
    application_applixware_aw,
    application_bdoc_bdoc,
    application_octet_stream_bin,
    image_bmp_bmp,
    application_octet_stream_bpk,
    application_octet_stream_buffer,
    application_ccxml_xml_ccxml,
    application_cdmi_capability_cdmia,
    application_cdmi_container_cdmic,
    application_cdmi_domain_cdmid,
    application_cdmi_object_cdmio,
    application_cdmi_queue_cdmiq,
    application_pkix_cert_cer,
    image_cgm_cgm,
    application_java_vm_class,
    text_coffeescript_coffee,
    text_plain_conf,
    application_mac_compactpro_cpt,
    application_pkix_crl_crl,
    text_css_css,
    text_csv_csv,
    application_cu_seeme_cu,
    application_davmount_xml_davmount,
    application_docbook_xml_dbk,
    application_octet_stream_deb,
    text_plain_def,
    application_octet_stream_deploy,
    message_disposition_notification_disposition_notification,
    application_octet_stream_dist,
    application_octet_stream_distz,
    application_octet_stream_dll,
    application_octet_stream_dmg,
    application_octet_stream_dms,
    application_msword_doc,
    application_msword_dot,
    image_dicom_rle_drle,
    application_dssc_der_dssc,
    application_xml_dtd_dtd,
    application_octet_stream_dump,
    application_java_archive_ear,
    application_ecmascript_ecma,
    application_octet_stream_elc,
    image_emf_emf,
    message_rfc822_eml,
    application_emma_xml_emma,
    application_postscript_eps,
    application_epub_zip_epub,
    application_ecmascript_es,
    application_octet_stream_exe,
    application_exi_exi,
    image_aces_exr,
    application_andrew_inset_ez,
    image_fits_fits,
    image_g3fax_g3,
    application_rpki_ghostbusters_gbr,
    application_geo_json_geojson,
    image_gif_gif,
    model_gltf_binary_glb,
    model_gltf_json_gltf,
    application_gml_xml_gml,
    application_gpx_xml_gpx,
    application_srgs_gram,
    application_srgs_xml_grxml,
    application_gxf_gxf,
    application_gzip_gz,
    video_h261_h261,
    video_h263_h263,
    video_h264_h264,
    image_heic_heic,
    image_heic_sequence_heics,
    image_heif_heif,
    image_heif_sequence_heifs,
    application_hjson_hjson,
    application_winhlp_hlp,
    application_mac_binhex40_hqx,
    text_html_htm,
    text_html_html,
    text_calendar_ics,
    image_ief_ief,
    text_calendar_ifb,
    model_iges_iges,
    model_iges_igs,
    application_octet_stream_img,
    text_plain_in,
    text_plain_ini,
    application_inkml_xml_ink,
    application_inkml_xml_inkml,
    application_ipfix_ipfix,
    application_octet_stream_iso,
    text_jade_jade,
    application_java_archive_jar,
    image_jls_jls,
    image_jp2_jp2,
    image_jpeg_jpe,
    image_jpeg_jpeg,
    image_jpx_jpf,
    image_jpeg_jpg,
    image_jp2_jpg2,
    video_jpm_jpgm,
    video_jpeg_jpgv,
    image_jpm_jpm,
    image_jpx_jpx,
    application_javascript_js,
    application_json_json,
    application_json5_json5,
    application_ld_json_jsonld,
    application_jsonml_json_jsonml,
    text_jsx_jsx,
    audio_midi_kar,
    image_ktx_ktx,
    text_less_less,
    text_plain_list,
    text_coffeescript_litcoffee,
    text_plain_log,
    application_lost_xml_lostxml,
    application_octet_stream_lrf,
    video_mpeg_m1v,
    application_mp21_m21,
    audio_mpeg_m2a,
    video_mpeg_m2v,
    audio_mpeg_m3a,
    audio_mp4_m4a,
    application_mp4_m4p,
    application_mathematica_ma,
    application_mads_xml_mads,
    text_troff_man,
    text_cache_manifest_manifest,
    application_json_map,
    application_octet_stream_mar,
    text_markdown_markdown,
    application_mathml_xml_mathml,
    application_mathematica_mb,
    application_mbox_mbox,
    text_markdown_md,
    text_troff_me,
    model_mesh_mesh,
    application_metalink4_xml_meta4,
    application_metalink_xml_metalink,
    application_mets_xml_mets,
    application_rpki_manifest_mft,
    audio_midi_mid,
    audio_midi_midi,
    message_rfc822_mime,
    video_mj2_mj2,
    video_mj2_mjp2,
    application_javascript_mjs,
    text_mathml_mml,
    application_mods_xml_mods,
    video_quicktime_mov,
    audio_mpeg_mp2,
    application_mp21_mp21,
    audio_mpeg_mp2a,
    audio_mpeg_mp3,
    video_mp4_mp4,
    audio_mp4_mp4a,
    application_mp4_mp4s,
    video_mp4_mp4v,
    application_dash_xml_mpd,
    video_mpeg_mpe,
    video_mpeg_mpeg,
    video_mpeg_mpg,
    video_mp4_mpg4,
    audio_mpeg_mpga,
    application_marc_mrc,
    application_marcxml_xml_mrcx,
    text_troff_ms,
    application_mediaservercontrol_xml_mscml,
    model_mesh_msh,
    application_octet_stream_msi,
    application_octet_stream_msm,
    application_octet_stream_msp,
    application_mxf_mxf,
    application_xv_xml_mxml,
    text_n3_n3,
    application_mathematica_nb,
    application_oda_oda,
    audio_ogg_oga,
    audio_ogg_ogg,
    video_ogg_ogv,
    application_ogg_ogx,
    application_omdoc_xml_omdoc,
    application_onenote_onepkg,
    application_onenote_onetmp,
    application_onenote_onetoc,
    application_onenote_onetoc2,
    application_oebps_package_xml_opf,
    font_otf_otf,
    application_rdf_xml_owl,
    application_oxps_oxps,
    application_pkcs10_p10,
    application_pkcs7_mime_p7c,
    application_pkcs7_mime_p7m,
    application_pkcs7_signature_p7s,
    application_pkcs8_p8,
    application_pdf_pdf,
    application_font_tdpfr_pfr,
    application_pgp_encrypted_pgp,
    application_octet_stream_pkg,
    application_pkixcmp_pki,
    application_pkix_pkipath_pkipath,
    application_pls_xml_pls,
    image_png_png,
    application_pics_rules_prf,
    application_postscript_ps,
    application_pskc_xml_pskcxml,
    video_quicktime_qt,
    application_raml_yaml_raml,
    application_rdf_xml_rdf,
    application_reginfo_xml_rif,
    application_resource_lists_xml_rl,
    application_resource_lists_diff_xml_rld,
    audio_midi_rmi,
    application_relax_ng_compact_syntax_rnc,
    application_xml_rng,
    application_rpki_roa_roa,
    text_troff_roff,
    application_sparql_query_rq,
    application_rls_services_xml_rs,
    application_rsd_xml_rsd,
    application_rss_xml_rss,
    application_rtf_rtf,
    text_richtext_rtx,
    audio_s3m_s3m,
    application_sbml_xml_sbml,
    application_scvp_cv_request_scq,
    application_scvp_cv_response_scs,
    application_sdp_sdp,
    application_java_serialized_object_ser,
    application_set_payment_initiation_setpay,
    application_set_registration_initiation_setreg,
    image_sgi_sgi,
    text_sgml_sgm,
    text_sgml_sgml,
    text_shex_shex,
    application_shf_xml_shf,
    text_html_shtml,
    application_pgp_signature_sig,
    audio_silk_sil,
    model_mesh_silo,
    text_slim_slim,
    text_slim_slm,
    application_smil_xml_smi,
    application_smil_xml_smil,
    audio_basic_snd,
    application_octet_stream_so,
    application_scvp_vp_response_spp,
    application_scvp_vp_request_spq,
    audio_ogg_spx,
    application_sru_xml_sru,
    application_sparql_results_xml_srx,
    application_ssdl_xml_ssdl,
    application_ssml_xml_ssml,
    application_hyperstudio_stk,
    text_stylus_styl,
    text_stylus_stylus,
    image_svg_xml_svg,
    image_svg_xml_svgz,
    text_troff_t,
    image_t38_t38,
    application_tei_xml_tei,
    application_tei_xml_teicorpus,
    text_plain_text,
    application_thraud_xml_tfi,
    image_tiff_fx_tfx,
    image_tiff_tif,
    image_tiff_tiff,
    text_troff_tr,
    video_mp2t_ts,
    application_timestamped_data_tsd,
    text_tab_separated_values_tsv,
    font_collection_ttc,
    font_ttf_ttf,
    text_turtle_ttl,
    text_plain_txt,
    message_global_delivery_status_u8dsn,
    message_global_headers_u8hdr,
    message_global_disposition_notification_u8mdn,
    message_global_u8msg,
    text_uri_list_uri,
    text_uri_list_uris,
    text_uri_list_urls,
    text_vcard_vcard,
    model_vrml_vrml,
    text_vtt_vtt,
    application_voicexml_xml_vxml,
    application_java_archive_war,
    application_wasm_wasm,
    audio_wav_wav,
    audio_webm_weba,
    video_webm_webm,
    application_manifest_json_webmanifest,
    image_webp_webp,
    application_widget_wgt,
    image_wmf_wmf,
    font_woff_woff,
    font_woff2_woff2,
    model_vrml_wrl,
    application_wsdl_xml_wsdl,
    application_wspolicy_xml_wspolicy,
    model_x3d_xml_x3d,
    model_x3d_binary_x3db,
    model_x3d_binary_x3dbz,
    model_x3d_vrml_x3dv,
    model_x3d_vrml_x3dvz,
    model_x3d_xml_x3dz,
    application_xaml_xml_xaml,
    application_xcap_diff_xml_xdf,
    application_dssc_xml_xdssc,
    application_xenc_xml_xenc,
    application_patch_ops_error_xml_xer,
    application_xhtml_xml_xht,
    application_xhtml_xml_xhtml,
    application_xv_xml_xhvml,
    audio_xm_xm,
    application_xml_xml,
    application_xop_xml_xop,
    application_xproc_xml_xpl,
    application_xml_xsd,
    application_xml_xsl,
    application_xslt_xml_xslt,
    application_xspf_xml_xspf,
    application_xv_xml_xvm,
    application_xv_xml_xvml,
    text_yaml_yaml,
    application_yang_yang,
    application_yin_xml_yin,
    text_yaml_yml,
    application_zip_zip
};

#endif
