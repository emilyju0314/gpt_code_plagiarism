Eina_Bool ewk_frame_uri_changed(Evas_Object* o)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->frame, EINA_FALSE);
    WTF::CString uri(sd->frame->document()->url().prettyURL().utf8());

    INF("uri=%s", uri.data());
    if (!uri.data()) {
        ERR("no uri");
        return EINA_FALSE;
    }

    eina_stringshare_replace(&sd->uri, uri.data());
    evas_object_smart_callback_call(o, "uri,changed", (void*)sd->uri);
    return EINA_TRUE;
}