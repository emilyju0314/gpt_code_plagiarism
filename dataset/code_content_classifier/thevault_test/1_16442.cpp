Eina_Bool ewk_view_setting_page_cache_get(Evas_Object* o)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, EINA_FALSE);
    return priv->settings.page_cache;
}