float ewk_view_zoom_get(const Evas_Object* o)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, -1.0);
    return ewk_frame_zoom_get(sd->main_frame);
}