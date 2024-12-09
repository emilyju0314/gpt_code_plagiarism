bool DownloadManager::cbResumeDownload(LSHandle* lshandle, LSMessage *message,void *user_data)
{
    LSError lserror;
    LSErrorInit(&lserror);

    const char* str = LSMessageGetPayload(message);
    if( !str )
        return false;

    std::string errorCode;
    std::string errorText;
    std::string extendedErrorText;
    std::string authToken;
    std::string deviceId;
    std::string key;
    bool subscribed = false;
    int rc = 0;
    int ticket = 0;
    JUtil::Error error;

    pbnjson::JValue root = JUtil::parse(str, "DownloadService.resumeDownload", &error);
    if (root.isNull()) {
        errorCode = ConvertToString<int>(DOWNLOADMANAGER_RESUMESTATUS_GENERALERROR);
        errorText = error.detail();
        goto Done_cbResumeDownload;
    }

    //get the ticket number parameter
    ticket = root["ticket"].asNumber<int>();
    authToken = root["authToken"].asString();
    deviceId = root["deviceId"].asString();

    key = ConvertToString<long>(ticket);

    if (LSMessageIsSubscription(message)) {

        if (!LSSubscriptionAdd(lshandle,key.c_str(), message, &lserror))
        {
            subscribed=false;
            LSErrorPrint (&lserror, stderr);
            LSErrorFree(&lserror);
        }
        else
            subscribed=true;

    }

    rc = DownloadManager::instance().resumeDownload(ticket,authToken,deviceId,extendedErrorText);

    errorCode = ConvertToString<int>(rc);
    switch (rc) {
    case DOWNLOADMANAGER_RESUMESTATUS_QUEUEFULL:
        errorText = "Download queue is full; cannot resume at this time";
        break;
    case DOWNLOADMANAGER_RESUMESTATUS_HISTORYCORRUPT:
    case DOWNLOADMANAGER_RESUMESTATUS_NOTDOWNLOAD:
    case DOWNLOADMANAGER_RESUMESTATUS_NOTINTERRUPTED:
    case DOWNLOADMANAGER_RESUMESTATUS_NOTINHISTORY:
    case DOWNLOADMANAGER_RESUMESTATUS_GENERALERROR:
        errorText = "Ticket provided does not correspond to an interrupted transfer in history";
        break;
    case DOWNLOADMANAGER_RESUMESTATUS_CANNOTACCESSTEMP:
        errorText = "Cannot access temporary file for append";
        break;
    default:
        errorText = extendedErrorText;
        break;
    }

Done_cbResumeDownload:

    root = pbnjson::Object();
    root.put("subscribed", subscribed);
    if (rc <= 0) {
        root.put("returnValue", false);
        root.put("errorCode", errorCode);
        root.put("errorText", errorText);
    }
    else
        root.put("returnValue", true);

    LSErrorInit(&lserror);
    if (!LSMessageReply( lshandle, message, JUtil::toSimpleString(root).c_str(), &lserror ))  {
        LSErrorPrint (&lserror, stderr);
        LSErrorFree(&lserror);
    }

    return true;
}