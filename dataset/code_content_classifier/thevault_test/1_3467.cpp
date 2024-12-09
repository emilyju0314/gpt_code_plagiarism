static void sqliteLogCallback(void *data, int iErrCode, const char *zMsg)
{
    // Extract line number for specific error codes.
    const char *pattern = NULL;
    int priority = ANDROID_LOG_WARN;
    switch (iErrCode & 0xFF) {
        case SQLITE_NOTICE:
            priority = ANDROID_LOG_INFO;
            break;
        case SQLITE_OK:
        case SQLITE_SCHEMA:
        case SQLITE_CONSTRAINT:
            priority = ANDROID_LOG_DEBUG;
            break;
        case SQLITE_CORRUPT:
            priority = ANDROID_LOG_ERROR;
            pattern = "database corruption at line %d of [";
            break;
        case SQLITE_MISUSE:
            priority = ANDROID_LOG_ERROR;
            pattern = "misuse at line %d of [";
            break;
        case SQLITE_CANTOPEN:
            priority = ANDROID_LOG_ERROR;
            pattern = "cannot open file at line %d of [";
            break;
    }

    if (pattern) {
        int lineno;
        int ret = sscanf(zMsg, pattern, &lineno);
        if (ret > 0)
            sLastErrorLine = lineno;
    }

    wcdb_log_print(priority, "WCDB.SQLite", "[SQLite ErrCode: %d] %s\n",
                   iErrCode, zMsg);
}