Eina_Bool ewk_view_setting_local_storage_database_path_set(Evas_Object* o, const char* path)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd, EINA_FALSE);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv, EINA_FALSE);
    if (eina_stringshare_replace(&priv->settings.local_storage_database_path, path))
        priv->page_settings->setLocalStorageDatabasePath(String::fromUTF8(path));
    return EINA_TRUE;
}