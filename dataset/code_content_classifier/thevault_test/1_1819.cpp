bool DownloadManager::cbListPendingDownloads(LSHandle * lshandle,LSMessage *msg,void * user_data) {


    LSError lserror;
    LSErrorInit(&lserror);
    std::string result;
    std::vector<std::string> list;

    int n = DownloadManager::instance().getJSONListOfAllDownloads(list);

    result  = "{ \"returnValue\":true , \"count\":"+ConvertToString<int>(n);
    if (n) {
        result += std::string(", \"downloads\": [ ");
        result += list.at(0);
        for (size_t i=1;i<list.size();i++) {
            result += std::string(", ")+list.at(i);
        }
        result += std::string(" ] ");
    }

    result += std::string("}");

    const char* r = result.c_str();
    if (!LSMessageReply( lshandle, msg, r, &lserror ))  {
        LSErrorPrint (&lserror, stderr);
        LSErrorFree(&lserror);
    }

    return true;
}