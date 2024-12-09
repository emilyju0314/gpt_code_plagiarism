Eina_Bool ewk_view_setting_encoding_detector_set(Evas_Object* o, Eina_Bool enable)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, EINA_FALSE);
    enable = !!enable;
    if (priv->settings.encoding_detector != enable) {
        priv->page_settings->setUsesEncodingDetector(enable);
        priv->settings.encoding_detector = enable;
    }
    return EINA_TRUE;
}