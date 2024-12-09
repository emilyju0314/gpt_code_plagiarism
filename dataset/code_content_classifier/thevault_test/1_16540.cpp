Eina_Bool ewk_settings_icon_database_path_set(const char *directory)
{
    WebCore::IconDatabase::delayDatabaseCleanup();

    if (directory) {
        struct stat st;

        if (stat(directory, &st)) {
            ERR("could not stat(%s): %s", directory, strerror(errno));
            return EINA_FALSE;
        }

        if (!S_ISDIR(st.st_mode)) {
            ERR("not a directory: %s", directory);
            return EINA_FALSE;
        }

        if (access(directory, R_OK | W_OK)) {
            ERR("could not access directory '%s' for read and write: %s",
                directory, strerror(errno));
            return EINA_FALSE;
        }

        WebCore::iconDatabase().setEnabled(true);
        WebCore::iconDatabase().open(WTF::String::fromUTF8(directory), WebCore::IconDatabase::defaultDatabaseFilename());
        if (!_ewk_icon_database_path)
            _ewk_icon_database_path = eina_stringshare_add(directory);
        else
            eina_stringshare_replace(&_ewk_icon_database_path, directory);
    } else {
        WebCore::iconDatabase().setEnabled(false);
        WebCore::iconDatabase().close();
        if (_ewk_icon_database_path) {
            eina_stringshare_del(_ewk_icon_database_path);
            _ewk_icon_database_path = 0;
        }
    }
    return EINA_TRUE;
}