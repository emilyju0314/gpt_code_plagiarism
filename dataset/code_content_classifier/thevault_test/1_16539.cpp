const char *ewk_settings_web_database_path_get(void)
{
#if ENABLE(DATABASE)
    return _ewk_default_web_database_path;
#else
    return 0;
#endif
}