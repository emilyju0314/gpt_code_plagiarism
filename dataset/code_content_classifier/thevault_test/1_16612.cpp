float ewk_frame_zoom_get(const Evas_Object* o)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, -1.0);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->frame, -1.0);

    if (sd->textZoom)
        return sd->frame->textZoomFactor();
    return sd->frame->pageZoomFactor();
}