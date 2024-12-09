bool DownloadManager::getDownloadTaskCopy(unsigned long ticket,DownloadTask& task) {

    std::map<long,DownloadTask*>::iterator iter = m_ticketMap.find(ticket);
    if (iter == m_ticketMap.end())
        return false;   //not found

    DownloadTask * ptrFoundTask = iter->second;
    if (ptrFoundTask == NULL) {
        //whoa! these 'NULL' entries should never occur..perhaps a more severe error flagging should be done here to alert about this case
        return false;
    }

    task.curlDesc = ptrFoundTask->curlDesc;
    task.bytesCompleted = ptrFoundTask->bytesCompleted;
    task.bytesTotal = ptrFoundTask->bytesTotal;
    task.destPath = ptrFoundTask->destPath.c_str();                 //Prevent CoW  (DEBUGGING)
    task.destFile = ptrFoundTask->destFile.c_str();                 //Prevent CoW  (DEBUGGING)
    task.ticket = ptrFoundTask->ticket;
    task.url = ptrFoundTask->url.c_str();                   //Prevent CoW  (DEBUGGING)
    task.setMimeType(ptrFoundTask->detectedMIMEType);   //Prevent CoW  (DEBUGGING)

    return true;
}