static bool cbAllow1x(LSHandle* lshandle, LSMessage *message,void *user_data)
{

    LSError lserror;
    LSErrorInit(&lserror);

    std::string errorText;
    JUtil::Error error;

    pbnjson::JValue root = JUtil::parse(LSMessageGetPayload(message), "DownloadService.allow1x", &error);
    if (root.isNull()) {
        errorText = error.detail();
    }

    pbnjson::JValue reply = pbnjson::Object();
    if( errorText.empty()) {
        DownloadManager::s_allow1x = root["value"].asBool();
        reply.put("returnValue", true);
        reply.put("value", DownloadManager::s_allow1x);
    }
    else {
        reply.put("returnValue", false);
        reply.put("errorText", errorText);
    }

    if  (!LSMessageReply( lshandle, message, JUtil::toSimpleString(reply).c_str(), &lserror )) {
        LSErrorPrint (&lserror, stderr);
        LSErrorFree(&lserror);
    }

    return true;
}