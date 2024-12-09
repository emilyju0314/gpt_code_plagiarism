Eina_Bool ewk_view_zoom_text_only_get(const Evas_Object* o)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    return ewk_frame_zoom_text_only_get(sd->main_frame);
}