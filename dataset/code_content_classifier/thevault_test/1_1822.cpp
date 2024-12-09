bool DownloadManager::cbClearDownloadHistory(LSHandle * lshandle,LSMessage *msg,void * user_data)
{
    LOG_DEBUG("Requst for clearing the download History");
    LSError lserror;
    LSErrorInit(&lserror);
    std::string historyCaller;
    std::string errorText;
    int errorCode = 0;
    JUtil::Error error;

    pbnjson::JValue root = JUtil::parse(LSMessageGetPayload(msg), "DownloadService.clearHistory", &error);
    if (root.isNull()) {
        errorCode = DOWNLOADHISTORYDB_HISTORYSTATUS_GENERALERROR;
        errorText = error.detail();
        goto Done;
    }

    if (!root.hasKey("owner")) {
        errorCode = DownloadManager::instance().clearDownloadHistory();
    } else {
        historyCaller = root["owner"].asString();
        errorCode = DownloadManager::instance().clearDownloadHistoryByGlobbedOwner(historyCaller);
    }

    switch (errorCode) {
        case DOWNLOADHISTORYDB_HISTORYSTATUS_HISTORYERROR:
            errorText = std::string("Internal error");
            break;
        case DOWNLOADHISTORYDB_HISTORYSTATUS_NOTINHISTORY:
            errorText = std::string("Fail to find owner");
            break;
    }

Done:

    //TODO: should probably return something more reflective of the actual result
    pbnjson::JValue replyJsonObj = pbnjson::Object();
    if (replyJsonObj.isNull())
        return false;

    if (errorCode > 0) {
        replyJsonObj.put("returnValue", false);
        replyJsonObj.put("errorCode", errorCode);
        replyJsonObj.put("errorText", errorText);
    }
    else
        replyJsonObj.put("returnValue", true);

    if (!LSMessageReply( lshandle, msg, JUtil::toSimpleString(replyJsonObj).c_str(), &lserror ))  {
        LSErrorPrint (&lserror, stderr);
        LSErrorFree(&lserror);
    }

    return true;
}