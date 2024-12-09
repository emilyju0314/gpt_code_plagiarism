size_t DownloadManager::cbHeader(CURL * taskHandle,size_t headerSize,const char * headerText)
{

    if (headerText == NULL)
    {
        //LOG_DEBUG ("%s: header text was null. Function-Exit-Early",__FUNCTION__);
        return headerSize;
    }
    //try and retrieve the task from the curl handle
    TransferTask * _task = getTask(taskHandle);
    if (_task == NULL)
    {
        //LOG_DEBUG ("%s: TransferTask not found in handle map. Function-Exit-Early",__FUNCTION__);
        return headerSize;
    }

    std::string header = headerText;

    ////LOG_DEBUG ("cbHeader(): %s\n",header.c_str());
    //find the :
    size_t labelendpos = header.find(":",0);
    if (labelendpos == std::string::npos) {
        //LOG_DEBUG ("%s: header string = %s (Function-Exit-Early)",__FUNCTION__,header.c_str());
        return headerSize;
    }

    std::string headerLabel = header.substr(0,labelendpos);
    std::transform(headerLabel.begin(), headerLabel.end(), headerLabel.begin(), tolower);

    std::string headerContent = header.substr(labelendpos+1,header.size());
    headerContent = trimWhitespace(headerContent);

    if (headerLabel.compare("location") == 0) {
        //possible redirect code...store it for later
        //LOG_DEBUG ("%s: Location header found: %s",__FUNCTION__,header.c_str());
        _task->setLocationHeader(headerContent);
        return headerSize;
    }

    //PAST THIS POINT, IT MUST BE A DOWNLOAD TASK

    if (_task->type != TransferTask::DOWNLOAD_TASK)
    {
        //LOG_DEBUG ("%s: TransferTask is not a Download. Function-Exit-Early",__FUNCTION__);
        return headerSize;
    }

    DownloadTask * task = _task->p_downloadTask;

    //LOG_DEBUG ("cbHeader(): headerLabel = %s , headerContent = %s\n",headerLabel.c_str(),headerContent.c_str());
    if (headerLabel.compare("content-length") == 0) {

        //LOG_DEBUG ("%s: BYTES RECEIVED SO FAR = %lu , BYTES TOTAL = %lu",__FUNCTION__,task->bytesCompleted,task->bytesTotal);
        //parse the length
        uint64_t contentLength = strtouq(headerContent.c_str(),NULL,10);

        if (contentLength == 0)
        {
            //LOG_DEBUG ("%s: Content-Length was 0",__FUNCTION__);
            return headerSize;          //get out early - content length 0 is useless info
        }
        else
        {
            //LOG_DEBUG ("%s: Content-Length was %lu",__FUNCTION__,contentLength);
        }
        //if initially the content-length was 0 and then some data was downloaded, and now the download is resuming,
        //              then the content length will be incorrect because the server is sending the REMAINING length
        //              ...fix it up by adding what was already received

        if ((task->bytesCompleted > 0) && (task->bytesTotal == 0))
        {
            task->bytesTotal = contentLength + task->bytesCompleted;
            task->setUpdateInterval();
            LOG_DEBUG ("%s: Fixing up Content-Length to %llu, and this looks like a Resume download",__FUNCTION__,task->bytesTotal);
        }
        else if (task->bytesCompleted == 0)
        {
            // THIS IS A FRESHLY STARTED DOWNLOAD, NOT A RESUME
            //LOG_DEBUG ("%s: Content-Length = %lu, and this is a FreshStart download",__FUNCTION__,task->bytesTotal);
            task->bytesTotal = contentLength;
            task->setUpdateInterval();
            //LOG_DEBUG ("%s: Updated Content-Length = %lu, and this is a FreshStart download",__FUNCTION__,task->bytesTotal);
            // 1.3.5 - try and "truncate" the file to the size reported, so that the space is "taken"
            /*
            int fdes;
            if ((fdes = fileno(task->fp)) != -1)
            {
                ::ftruncate(fdes,task->bytesTotal);
            }
            */

        }
    }
    else if (headerLabel.compare("content-type") == 0) {
        //get the MIME type that the server is reporting
        task->setMimeType(headerContent);
    }

//    LOG_DEBUG ("%s Function-Exit",__FUNCTION__);
    return headerSize;
}