bool DownloadManager::cbGetAllHistory(LSHandle * lshandle,LSMessage *msg, void * user_data)
{
    LSError lserror;
    std::string historyCaller;
    std::string errorText;
    std::vector<DownloadHistoryDb::DownloadHistory> historyList;
    LSErrorInit(&lserror);
    bool retVal=false;
    JUtil::Error error;

    pbnjson::JValue root = JUtil::parse(LSMessageGetPayload(msg), "DownloadService.getAllHistory", &error);
    if (root.isNull()) {
        errorText = error.detail();
        goto Done;
    }

    historyCaller = root["owner"].asString();
    LOG_DEBUG("Requested for download-history by owner [%s]",historyCaller.c_str() );
    retVal = DownloadManager::instance().getDownloadHistoryAllByCaller(historyCaller, historyList);

    if (!retVal)
        errorText = "not_found";

Done:

    pbnjson::JValue repleyJsonObj = pbnjson::Object();
    if (retVal)
    {
        //go through every result returned
        pbnjson::JValue resultArray = pbnjson::Array();

        for (std::vector<DownloadHistoryDb::DownloadHistory>::iterator it = historyList.begin();
                it != historyList.end();++it)
        {
            pbnjson::JValue item = pbnjson::Object();
            item.put("interface", it->m_interface);
            item.put("ticket", (int64_t)it->m_ticket);
            item.put("state", it->m_state);
            item.put("recordString", it->m_downloadRecordJsonString);

            pbnjson::JValue statusObj = JUtil::parse(it->m_downloadRecordJsonString.c_str(), std::string(""));
            if (!statusObj.isNull())
            {
                for(pbnjson::JValue::ObjectIterator it = statusObj.begin(); it != statusObj.end(); ++it)
                {
                    std::string strKey = (*it).first.asString();
                    if (strKey == std::string("target"))
                    {
                       std::string strVal = (*it).second.asString();
                       if (doesExistOnFilesystem(strVal.c_str()))
                        {
                            item.put("fileExistsOnFilesys", true);
                            item.put("fileSizeOnFilesys", filesizeOnFilesystem(strVal.c_str()));
                        }
                        else
                        {
                            item.put("fileExistsOnFilesys", false);
                        }
                    }
                }
            }
            resultArray.append(item);
        }
        repleyJsonObj.put("returnValue", true);
        repleyJsonObj.put("items", resultArray);

    }
    else
    {
        //total fail
        repleyJsonObj.put("returnValue", false);
        repleyJsonObj.put("errorText", errorText);
    }

    LSErrorInit(&lserror);
    if (!LSMessageReply( lshandle, msg, JUtil::toSimpleString(repleyJsonObj).c_str(), &lserror )) {
        LSErrorPrint (&lserror, stderr);
        LSErrorFree(&lserror);
    }

    return true;
}