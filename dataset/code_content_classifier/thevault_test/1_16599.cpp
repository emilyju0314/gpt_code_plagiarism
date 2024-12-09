Eina_Bool ewk_frame_uri_set(Evas_Object* o, const char* uri)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    WebCore::KURL kurl(WebCore::KURL(), WTF::String::fromUTF8(uri));
    WebCore::ResourceRequest req(kurl);
    WebCore::FrameLoader* loader = sd->frame->loader();
    loader->load(req, false);
    return EINA_TRUE;
}