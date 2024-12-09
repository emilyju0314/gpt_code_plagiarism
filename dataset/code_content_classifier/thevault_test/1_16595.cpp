Evas_Object* ewk_frame_view_get(const Evas_Object* o)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, 0);
    return sd->view;
}