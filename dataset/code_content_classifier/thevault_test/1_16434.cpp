Eina_Bool ewk_view_setting_enable_auto_resize_window_get(const Evas_Object* o)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, EINA_FALSE);
    return priv->settings.enable_auto_resize_window;
}