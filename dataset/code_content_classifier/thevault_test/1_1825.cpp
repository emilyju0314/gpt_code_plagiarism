bool DownloadManager::cbConnectionType(LSHandle* lshandle, LSMessage *message,void *user_data)
{
    const char* str = LSMessageGetPayload(message);
    if( !str )
        return false;

    bool is1x = DownloadManager::instance().is1xConnection();

    pbnjson::JValue responseRoot = pbnjson::Object();

    responseRoot.put("returnValue", true);
    responseRoot.put("1x", is1x);

    LSError lserror;
    LSErrorInit(&lserror);
    if (!LSMessageReply( lshandle, message, JUtil::toSimpleString(responseRoot).c_str(), &lserror ))  {
        LSErrorPrint (&lserror, stderr);
        LSErrorFree(&lserror);
    }

    return true;

}