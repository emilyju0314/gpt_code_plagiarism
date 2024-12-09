bool DownloadManager::cbUpload (LSHandle* lshandle, LSMessage* msg, void* user_data)
{

    pbnjson::JValue jo_postheaders;
    std::vector<PostItem> postHeaders;

    pbnjson::JValue jo_httpheaders;
    std::vector<std::string> httpHeaders;

    pbnjson::JValue jo_cookies;
    std::vector<kvpair> cookies;

    std::string contentType;
    std::string filePostLabel;
    std::string targetUrl;
    std::string inputFile;
    std::string errorText;
    int errorCode = 0;

    uint32_t uploadId = 0;
    bool subscribed = false;
    std::string subkey;
    boost::regex regURL("^(https?|ftp):\\/\\/(-\\.)?([^[:space:]/?\\.#-]+\\.?)+(/[^[:space:]]*)?$");
    boost::regex regMIME("^([^[:space:]]+)\\/([^[:space:]]+)$");

    JUtil::Error error;
    pbnjson::JValue root = JUtil::parse(LSMessageGetPayload(msg), "DownloadService.upload", &error);
    if (root.isNull()) {
        errorCode = DOWNLOADMANAGER_UPLOADSTATUS_GENERALERROR;
        errorText = error.detail();
        goto Done_cbUp;
    }

    //REQUIRED PARAMS
    targetUrl = root["url"].asString();
    inputFile = root["fileName"].asString();

    //OPTIONAL PARAMS
    contentType = root["contentType"].asString();
    filePostLabel = root["fileLabel"].asString();

    jo_postheaders = root["postParameters"];

    /*
    postParameters: [
          {"key":<string> , "data":<string; literal data> , "contentType":<string; mime type of part> },
                     ...
       ],
    */

    // check URL parameter validity
    if (!boost::regex_match(targetUrl, regURL)) {
        errorCode = DOWNLOADMANAGER_UPLOADSTATUS_INVALIDPARAM;
        errorText = "Invalid URL";
        goto Done_cbUp;
    }

    // check MIME parameter validity
    if (root.hasKey("contentType")) {
        if (!boost::regex_match(contentType, regMIME)) {
            errorCode = DOWNLOADMANAGER_UPLOADSTATUS_INVALIDPARAM;
            errorText = "Invalid MIME type";
            goto Done_cbUp;
        }
    }

    if (!jo_postheaders.isNull()) {
        pbnjson::JValue jo;
        for (int idx=0;idx<jo_postheaders.arraySize();++idx) {
            jo = jo_postheaders[idx];
            if (jo.isNull())
                continue;

            std::string key,data,contentType;
            key = jo["key"].asString();
            data = jo["data"].asString();
            contentType = jo["contentType"].asString();

            // check MIME parameter validity in "postParameters"
            if(jo.hasKey("contentType")) {
                if (!boost::regex_match(contentType, regMIME)) {
                    errorCode = DOWNLOADMANAGER_UPLOADSTATUS_INVALIDPARAM;
                    errorText = "Invalid MIME type";
                    goto Done_cbUp;
                }
            }

            postHeaders.push_back(PostItem(key,data,PostItem::Value,contentType));
        }
    }

    jo_cookies = root["cookies"];
    if (!jo_cookies.isNull()) {
        for(pbnjson::JValue::ObjectIterator it = jo_cookies.begin(); it != jo_cookies.end(); ++it )
        {
            cookies.push_back(std::pair<std::string,std::string>((*it).first.asString(), (*it).second.asString()));
        }
    }

    jo_httpheaders = root["customHttpHeaders"];
    if (!jo_httpheaders.isNull()) {
        pbnjson::JValue jo;
        for (int idx=0;idx<jo_httpheaders.arraySize();++idx) {
            jo = jo_httpheaders[idx];
            if (jo.isNull())
                continue;
            std::string s = JUtil::toSimpleString(jo);
            httpHeaders.push_back(s);
        }
    }

    uploadId = DownloadManager::instance().uploadPOSTFile(inputFile,targetUrl,filePostLabel,postHeaders,httpHeaders,cookies,contentType);
    if (uploadId == 0) {
        errorCode = DOWNLOADMANAGER_UPLOADSTATUS_GENERALERROR;
        errorText = "Failed to start upload";
        goto Done_cbUp;
    }

    subkey = std::string("UPLOAD_")+ConvertToString<uint32_t>(uploadId);
    if (processSubscription(lshandle,msg,subkey)) {
        subscribed = true;
    }

Done_cbUp:

    pbnjson::JValue replyJsonObj = pbnjson::Object();
    if (errorCode > 0) {
        replyJsonObj.put("returnValue", false);
        replyJsonObj.put("errorCode", errorCode);
        replyJsonObj.put("errorText", errorText);
    }
    else {
        replyJsonObj.put("returnValue", true);
        replyJsonObj.put("ticket", (int64_t)uploadId);
        replyJsonObj.put("subscribed", subscribed);
    }
    LSError lserror;
    LSErrorInit(&lserror);
    if (!LSMessageReply( lshandle, msg, JUtil::toSimpleString(replyJsonObj).c_str(), &lserror ))  {
        LSErrorPrint (&lserror, stderr);
        LSErrorFree(&lserror);
    }

    return true;
}