Eina_Bool ewk_view_pre_render_region(Evas_Object* o, Evas_Coord x, Evas_Coord y, Evas_Coord w, Evas_Coord h, float zoom)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->api->pre_render_region, EINA_FALSE);
    float cur_zoom;
    Evas_Coord cw, ch;

    /* When doing animated zoom it's not possible to call pre-render since it
     * would screw up parameters that animation is currently using
     */
    if (priv->animated_zoom.animator)
        return EINA_FALSE;

    cur_zoom = ewk_frame_zoom_get(sd->main_frame);

    if (cur_zoom < 0.00001)
        return EINA_FALSE;
    if (!ewk_frame_contents_size_get(sd->main_frame, &cw, &ch))
        return EINA_FALSE;

    cw *= zoom / cur_zoom;
    ch *= zoom / cur_zoom;
    DBG("region %d,%d+%dx%d @ %f contents=%dx%d", x, y, w, h, zoom, cw, ch);

    if (x + w > cw)
        w = cw - x;

    if (y + h > ch)
        h = ch - y;

    if (x < 0) {
        w += x;
        x = 0;
    }
    if (y < 0) {
        h += y;
        y = 0;
    }

    return sd->api->pre_render_region(sd, x, y, w, h, zoom);
}