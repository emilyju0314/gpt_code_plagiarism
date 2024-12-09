WTF::PassRefPtr<WebCore::Frame> ewk_view_frame_create(Evas_Object* o, Evas_Object* frame, const WTF::String& name, WebCore::HTMLFrameOwnerElement* ownerElement, const WebCore::KURL& url, const WTF::String& referrer)
{
    DBG("o=%p, frame=%p, name=%s, ownerElement=%p, url=%s, referrer=%s",
        o, frame, name.utf8().data(), ownerElement,
        url.prettyURL().utf8().data(), referrer.utf8().data());

    EWK_VIEW_SD_GET_OR_RETURN(o, sd, 0);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, 0);

    WTF::RefPtr<WebCore::Frame> cf = _ewk_view_core_frame_new
        (sd, priv, ownerElement);
    if (!cf) {
        ERR("Could not create child core frame '%s'", name.utf8().data());
        return 0;
    }

    if (!ewk_frame_child_add(frame, cf, name, url, referrer)) {
        ERR("Could not create child frame object '%s'", name.utf8().data());
        return 0;
    }

    // The creation of the frame may have removed itself already.
    if (!cf->page() || !cf->tree() || !cf->tree()->parent())
        return 0;

    sd->changed.frame_rect = EINA_TRUE;
    _ewk_view_smart_changed(sd);

    evas_object_smart_callback_call(o, "frame,created", frame);
    return cf.release();
}