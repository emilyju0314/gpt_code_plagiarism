Eina_Bool ewk_frame_contents_size_get(const Evas_Object* o, Evas_Coord* w, Evas_Coord* h)
{
    if (w)
        *w = 0;
    if (h)
        *h = 0;
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    if (w)
        *w = sd->contents_size.w;
    if (h)
        *h = sd->contents_size.h;
    return EINA_TRUE;
}