void ewk_view_theme_set(Evas_Object* o, const char* path)
{
    EWK_VIEW_SD_GET_OR_RETURN(o, sd);
    EWK_VIEW_PRIV_GET_OR_RETURN(sd, priv);
    if (!eina_stringshare_replace(&priv->settings.theme, path))
        return;
    ewk_frame_theme_set(sd->main_frame, path);
}