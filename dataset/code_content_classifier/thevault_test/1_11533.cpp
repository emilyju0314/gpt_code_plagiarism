void CIMAPBodyStruct::attachmentFn([[maybe_unused]] std::unique_ptr<BodyNode> &bodyNode, BodyPart &bodyPart, std::shared_ptr<void> &attachmentData)
    {
        AttachmentData *attachments{static_cast<AttachmentData *>(attachmentData.get())};
        std::unordered_map<std::string, std::string> dispositionMap;
        std::string disposition{bodyPart.parsedPart->disposition};
        if (!CIMAPParse::stringStartsWith(disposition, kNIL))
        {
            disposition = disposition.substr(1);
            while (!disposition.empty())
            {
                std::string item, value;
                parseNext(disposition, item);
                parseNext(disposition, value);
                dispositionMap.insert({CIMAPParse::stringToUpper(item), value});
            }
            std::string attachmentLabel;
            auto findAttachment = dispositionMap.find(kATTACHMENT);
            auto findInline = dispositionMap.find(kINLINE);
            if (findAttachment != dispositionMap.end())
            {
                attachmentLabel = kATTACHMENT;
            }
            else if (findInline != dispositionMap.end())
            {
                attachmentLabel = kINLINE;
            }
            if (!attachmentLabel.empty())
            {
                disposition = dispositionMap[attachmentLabel];
                if (!CIMAPParse::stringStartsWith(disposition, kNIL))
                {
                    dispositionMap.clear();
                    disposition = disposition.substr(1);
                    while (!disposition.empty())
                    {
                        std::string item, value;
                        parseNext(disposition, item);
                        parseNext(disposition, value);
                        dispositionMap.insert({CIMAPParse::stringToUpper(item), value});
                    }
                    Attachment fileAttachment;
                    fileAttachment.creationDate = dispositionMap[kCREATIONDATE];
                    fileAttachment.fileName = dispositionMap[kFILENAME];
                    fileAttachment.modifiactionDate = dispositionMap[kMODIFICATIONDATE];
                    fileAttachment.size = dispositionMap[kSIZE];
                    fileAttachment.partNo = bodyPart.partNo;
                    fileAttachment.encoding = bodyPart.parsedPart->encoding;
                    attachments->attachmentsList.push_back(fileAttachment);
                }
            }
        }
    }