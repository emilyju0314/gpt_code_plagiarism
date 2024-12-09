bool DownloadManager::cbCancelDownload(LSHandle* lshandle, LSMessage *msg, void *user_data) {

    LSError lserror;
    LSErrorInit(&lserror);

    unsigned long ticket_id=0;

    bool success = false;
    JUtil::Error error;

    pbnjson::JValue root = JUtil::parse(LSMessageGetPayload(msg), "DownloadService.cancelDownload", &error);
    if (root.isNull()) {
        success = false;
        goto Done;
    }

    ticket_id = root["ticket"].asNumber<int64_t>();

    success = true;
    //kill this task
    if (!DownloadManager::instance().cancel(ticket_id)) {
        LOG_DEBUG ("Function cancel() failed: id:(%lu)", ticket_id);
    }

    Done:

    pbnjson::JValue repleyJsonObj = pbnjson::Object();
    repleyJsonObj.put("ticket", (int64_t)ticket_id);
    repleyJsonObj.put("returnValue", success);
    if (!success)
        repleyJsonObj.put("errorText", error.detail());
    else {
        //to retain compatibility with older clients, inject some status here
        repleyJsonObj.put("aborted", true);
        repleyJsonObj.put("completed", false);
        repleyJsonObj.put("completionStatusCode", DOWNLOADMANAGER_COMPLETIONSTATUS_CANCELLED);
    }
    if (!LSMessageReply( lshandle, msg, JUtil::toSimpleString(repleyJsonObj).c_str(), &lserror ))   {
        LSErrorPrint (&lserror, stderr);
        LSErrorFree(&lserror);
    }

    return true;
}