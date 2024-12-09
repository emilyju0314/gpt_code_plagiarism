Eina_Bool ewk_view_zoom_animated_mark_stop(Evas_Object* o)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    _ewk_view_zoom_animated_mark_stop(sd);
    return EINA_TRUE;
}