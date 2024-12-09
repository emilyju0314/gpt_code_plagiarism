Eina_Bool ewk_view_pre_render_relative_radius(Evas_Object* o, unsigned int n)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, EINA_FALSE);
    EINA_SAFETY_ON_NULL_RETURN_VAL(sd->api->pre_render_relative_radius, EINA_FALSE);
    float cur_zoom;

    if (priv->animated_zoom.animator)
        return EINA_FALSE;

    cur_zoom = ewk_frame_zoom_get(sd->main_frame);
    return sd->api->pre_render_relative_radius(sd, n, cur_zoom);
}