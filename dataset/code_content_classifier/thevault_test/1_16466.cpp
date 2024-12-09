void ewk_view_window_close(Evas_Object* o)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd);

    ewk_view_stop(o);
    if (!sd->api->window_close)
        return;
    sd->api->window_close(sd);
}