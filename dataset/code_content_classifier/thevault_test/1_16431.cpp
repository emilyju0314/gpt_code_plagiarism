Eina_Bool ewk_view_zoom_text_only_set(Evas_Object* o, Eina_Bool setting)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    return ewk_frame_zoom_text_only_set(sd->main_frame, setting);
}