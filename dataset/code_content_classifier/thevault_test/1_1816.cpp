bool DownloadManager::cbPauseDownload(LSHandle* lshandle, LSMessage *message,void *user_data)
{
    LSError lserror;
    LSErrorInit(&lserror);

    const char* str = LSMessageGetPayload(message);
    if( !str )
        return false;

    std::string errorCode;
    std::string errorText;

    int rc = 0;
    int ticket = 0;

    JUtil::Error error;

    pbnjson::JValue root = JUtil::parse(str, "DownloadService.pauseDownload", &error);
    if (root.isNull()) {
        errorCode = ConvertToString<int>(DOWNLOADMANAGER_PAUSESTATUS_GENERALERROR);
        errorText = error.detail();
        goto Done_cbPauseDownload;
    }

    //get the ticket number parameter
    ticket = root["ticket"].asNumber<int>();

    rc = DownloadManager::instance().pauseDownload(ticket);

    switch (rc) {
    case DOWNLOADMANAGER_PAUSESTATUS_NOSUCHDOWNLOADTASK:
        errorCode = ConvertToString<int>(rc);
        errorText = "Ticket provided does not correspond to a downloading transfer";
        break;
    }

Done_cbPauseDownload:

    root = pbnjson::Object();
    if (rc <= 0) {
        root.put("returnValue", false);
        root.put("errorCode", errorCode);
        root.put("errorText", errorText);
    }
    else
        root.put("returnValue", true);

    if (!LSMessageReply( lshandle, message, JUtil::toSimpleString(root).c_str(), &lserror ))  {
        LSErrorPrint (&lserror, stderr);
        LSErrorFree(&lserror);
    }

    return true;
}