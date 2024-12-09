Eina_Bool ewk_frame_zoom_text_only_get(const Evas_Object* o)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    return sd->textZoom;
}