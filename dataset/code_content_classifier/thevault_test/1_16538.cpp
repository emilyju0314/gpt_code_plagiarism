void ewk_settings_web_database_path_set(const char *path)
{
#if ENABLE(DATABASE)
    WTF::String corePath = WTF::String::fromUTF8(path);
    WebCore::DatabaseTracker::tracker().setDatabaseDirectoryPath(corePath);
    if (!_ewk_default_web_database_path)
        _ewk_default_web_database_path = eina_stringshare_add(corePath.utf8().data());
    else
        eina_stringshare_replace(&_ewk_default_web_database_path, corePath.utf8().data());

#endif
}