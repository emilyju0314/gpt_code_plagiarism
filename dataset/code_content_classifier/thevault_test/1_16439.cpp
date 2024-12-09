Eina_Bool ewk_view_setting_spatial_navigation_set(Evas_Object* o, Eina_Bool enable)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, EINA_FALSE);
    enable = !!enable;
    if (priv->settings.spatial_navigation != enable) {
        priv->page_settings->setSpatialNavigationEnabled(enable);
        priv->settings.spatial_navigation = enable;
    }
    return EINA_TRUE;
}