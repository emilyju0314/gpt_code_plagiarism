Eina_Bool ewk_view_navigate_possible(Evas_Object* o, int steps)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    return ewk_frame_navigate_possible(sd->main_frame, steps);
}