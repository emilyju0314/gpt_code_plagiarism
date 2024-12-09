int DownloadManager::getJSONListOfAllDownloads(std::vector<std::string>& downloadList) {

    //walk one of the download maps via an iterator
    std::map<long,DownloadTask*>::iterator iter = m_ticketMap.begin();
    int i =0;
    while (iter != m_ticketMap.end()) {

        DownloadTask * task = iter->second;
        if (task == NULL)
            continue;       //this shouldn't happen!

                //TODO: maybe a harsher response for debugging purposes; error of this type can't really be handled here
                //- but if it happens, root cause should be found and fixed
        pbnjson::JValue jobj = task->toJSON();
        jobj.put("lastUpdateAt", (int64_t)task->lastUpdateAt);
        jobj.put("queued", task->queued);
        jobj.put("owner", task->ownerId);
        jobj.put("connectionName", task->connectionName);
        downloadList.push_back(JUtil::toSimpleString(jobj));
        iter++;
        ++i;
    }
    return i;
}