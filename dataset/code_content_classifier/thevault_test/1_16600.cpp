const char* ewk_frame_uri_get(const Evas_Object* o)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, 0);
    return sd->uri;
}