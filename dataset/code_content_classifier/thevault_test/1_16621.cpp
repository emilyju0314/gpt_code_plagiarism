Eina_Bool ewk_frame_init(Evas_Object* o, Evas_Object* view, WebCore::Frame* frame)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    if (!sd->frame) {
        WebCore::FrameLoaderClientEfl* flc = _ewk_frame_loader_efl_get(frame);
        flc->setWebFrame(o);
        sd->frame = frame;
        sd->view = view;
        frame->init();
        return EINA_TRUE;
    }

    ERR("frame %p already set for %p, ignored new %p",
        sd->frame, o, frame);
    return EINA_FALSE;
}