bool DownloadManager::cbCancelAllDownloads(LSHandle* lshandle, LSMessage *msg,
                            void *user_data) {

    LSError lserror;
    LSErrorInit(&lserror);
    std::string result;

    DownloadManager::instance().cancelAll();

    result  = "{ \"returnValue\":true }";

    const char* r = result.c_str();
    if (!LSMessageReply( lshandle, msg, r, &lserror ))  {
        LSErrorPrint (&lserror, stderr);
        LSErrorFree(&lserror);
    }

    return true;
}