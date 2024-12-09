const char* ewk_view_setting_local_storage_database_path_get(const Evas_Object* o)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, 0);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, 0);
    return priv->settings.local_storage_database_path;
}