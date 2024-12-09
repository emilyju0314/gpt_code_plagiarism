Eina_Bool ewk_view_forward_possible(Evas_Object* o)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    return ewk_frame_forward_possible(sd->main_frame);
}