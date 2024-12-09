void ewk_view_fixed_layout_size_get(Evas_Object* o, Evas_Coord* w, Evas_Coord* h)
{
    if (w)
        *w = 0;
    if (h)
        *h = 0;
    EWK_VIEW_SD_GET_OR_RETURN(o, sd);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv);
    if (priv->fixed_layout.use) {
        if (w)
            *w = priv->fixed_layout.w;
        if (h)
            *h = priv->fixed_layout.h;
    }
}