Eina_Bool ewk_frame_zoom_text_only_set(Evas_Object* o, Eina_Bool setting)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->frame, EINA_FALSE);
    if (sd->textZoom == setting)
        return EINA_TRUE;

    float zoom_level = sd->textZoom ? sd->frame->textZoomFactor() : sd->frame->pageZoomFactor();
    sd->textZoom = setting;
    if (sd->textZoom)
        sd->frame->setPageAndTextZoomFactors(1, zoom_level);
    else
        sd->frame->setPageAndTextZoomFactors(zoom_level, 1);
    return EINA_TRUE;
}