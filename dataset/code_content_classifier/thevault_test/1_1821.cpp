bool DownloadManager::cbDeleteDownloadedFile(LSHandle* lshandle, LSMessage *msg,void *user_data)
{
    LSError lserror;
    std::string result;
    std::string historyCaller;
    std::string historyState;
    std::string historyInterface;
    std::string errorText;
    std::string targetStr;
    std::string key = "0";

    DownloadTask task;
    unsigned long ticket_id=0;

    LSErrorInit(&lserror);
    JUtil::Error error;
    bool success = false;

    pbnjson::JValue root = JUtil::parse(LSMessageGetPayload(msg), "DownloadService.deleteDownloadedFile", &error);
    pbnjson::JValue resultRoot;
    if (root.isNull()) {
        success = false;
        errorText = error.detail();
        goto Done;
    }

    ticket_id = root["ticket"].asNumber<int64_t>();
    key = ConvertToString<long>(ticket_id);

    //retrieve the info of this ticket from download manager's task map

    if (DownloadManager::instance().getDownloadTaskCopy(ticket_id,task)) {
        //found it in currently downloading tasks
        //can't delete it while it is downloading
        success=false;
        errorText = std::string("cannot delete since file is still downloading");
        goto Done;
    }
    else if (DownloadManager::instance().getDownloadHistory(ticket_id,historyCaller,historyInterface,historyState,result)) { //try the db history
            //parse out the destination
            resultRoot = JUtil::parse(result.c_str(), std::string(""));
            if (resultRoot.isNull())
            {
                success = false;
                errorText = std::string("cannot delete; missing target property in history record");
                goto Done;
            }
            if (!resultRoot.hasKey("target"))
            {
                success = false;
                errorText = std::string("cannot delete; bad target property in history record");
                goto Done;
            }
            success=true;
            targetStr = resultRoot["target"].asString();
            Utils::remove_file(targetStr);      //if the file is not found, no big deal; consider it deleted!
            result = result = std::string("{\"ticket\":")+key+std::string(" , \"returnValue\":true }");
    }
    else {
        success =false;
        errorText = std::string("requested download record not found");
    }

    Done:

    if (!success) {
        result = std::string("{\"ticket\":")
        +key+std::string(" , \"returnValue\":false , \"errorText\":\"")+errorText+std::string("\" }");
    }
    const char* r = result.c_str();
    if (!LSMessageReply( lshandle, msg, r, &lserror )) {
        LSErrorPrint (&lserror, stderr);
        LSErrorFree(&lserror);
    }

    return true;
}