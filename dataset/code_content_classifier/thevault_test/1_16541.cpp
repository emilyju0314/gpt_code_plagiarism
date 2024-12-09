const char* ewk_settings_icon_database_path_get(void)
{
    if (!WebCore::iconDatabase().isEnabled())
        return 0;
    if (!WebCore::iconDatabase().isOpen())
        return 0;

    return _ewk_icon_database_path;
}