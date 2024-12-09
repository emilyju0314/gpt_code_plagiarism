Eina_Bool ewk_view_uri_set(Evas_Object* o, const char* uri)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    return ewk_frame_uri_set(sd->main_frame, uri);
}