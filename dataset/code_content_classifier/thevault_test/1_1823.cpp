bool DownloadManager::cbDownloadStatusQuery(LSHandle* lshandle, LSMessage *msg, void *user_data) {
    LSError lserror;
    std::string result;
    std::string historyCaller;
    std::string historyState;
    std::string historyInterface;
    std::string errorText;
    std::string subscribeKey = "0";

    DownloadTask task;
    unsigned long ticket_id=0;

    LSErrorInit(&lserror);

    bool fromTicketMap = false;
    bool fromHistory = false;
    bool retVal = false;
    JUtil::Error error;

    pbnjson::JValue root = JUtil::parse(LSMessageGetPayload(msg), "DownloadService.downloadStatusQuery", &error);
    if (root.isNull()) {
        errorText = error.detail();
        goto Done;
    }

    ticket_id = root["ticket"].asNumber<int64_t>();
    subscribeKey = ConvertToString<long>(ticket_id);
    LOG_DEBUG ("DownloadStatusQuery : ticket - %lu ", ticket_id);

    //retrieve the info of this ticket from download manager's task map
    if (DownloadManager::instance().getDownloadTaskCopy(ticket_id,task)) {
        //found it in currently downloading tasks
        fromTicketMap = true;
    }
    else {
        //try the db history
        fromHistory = DownloadManager::instance().getDownloadHistory (ticket_id, historyCaller, historyInterface, historyState, result);
        if (!fromHistory)
            errorText = "ticket_not_found";
    }

Done:

    pbnjson::JValue responseRoot = pbnjson::Object();
    std::string lbuff;
    responseRoot.put("ticket", (int64_t)ticket_id);
    if (fromTicketMap)
    {
        responseRoot.put("url", task.url);

        lbuff = Utils::toString(task.bytesCompleted);
        responseRoot.put("amountReceived", (int32_t)(task.bytesCompleted));
        responseRoot.put("e_amountReceived", lbuff);

        lbuff = Utils::toString(task.bytesTotal);
        responseRoot.put("amountTotal", (int32_t)(task.bytesTotal));
        responseRoot.put("e_amountTotal", lbuff);

        if (LSMessageIsSubscription(msg)) {
            retVal = LSSubscriptionAdd(lshandle,subscribeKey.c_str(), msg, &lserror);
            if (!retVal) {
                responseRoot.put("subscribed", false);
                LSErrorPrint (&lserror, stderr);
                LSErrorFree(&lserror);
            }
            else
                responseRoot.put("subscribed", true);
        }
        responseRoot.put("returnValue", true);
    }
    else if (fromHistory)
    {
        pbnjson::JValue resultObject = JUtil::parse(result.c_str(), std::string(""));
        if (resultObject.isNull())
        {
            LOG_DEBUG ("%s: fromHistory: error in parsing 'result' object [%s]",__FUNCTION__,result.c_str());
            responseRoot.put("returnValue", false);
            responseRoot.put("subscribed", false);
            responseRoot.put("errorText", std::string("db_error"));
        }
        else {
            for(pbnjson::JValue::ObjectIterator it = resultObject.begin(); it != resultObject.end(); ++it )
            {
                responseRoot.put((*it).first.asString(), (*it).second);
            }
            responseRoot.put("owner", historyCaller);
            responseRoot.put("interface", historyInterface);
            responseRoot.put("state", historyState);

            if (LSMessageIsSubscription(msg)) {
                retVal = LSSubscriptionAdd(lshandle,subscribeKey.c_str(), msg, &lserror);
                if (!retVal) {
                    responseRoot.put("subscribed", false);
                    LSErrorPrint (&lserror, stderr);
                    LSErrorFree(&lserror);
                }
                else
                    responseRoot.put("subscribed", true);
            }
            responseRoot.put("returnValue", true);
        }
    }
    else
    {
        //total fail
        responseRoot.put("returnValue", false);
        responseRoot.put("subscribed", false);
        responseRoot.put("errorText", errorText);
    }

    LSErrorInit(&lserror);
    if (!LSMessageReply( lshandle, msg, JUtil::toSimpleString(responseRoot).c_str(), &lserror )) {
        LSErrorPrint (&lserror, stderr);
        LSErrorFree(&lserror);
    }

    return true;
}