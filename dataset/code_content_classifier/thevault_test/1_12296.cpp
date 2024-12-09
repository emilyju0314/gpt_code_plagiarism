AZ::Outcome<void, AZStd::string> ValidateJsonClassHeader(const rapidjson::Document& jsonDocument)
    {
        auto typeItr = jsonDocument.FindMember(FileTypeTag);
        if (typeItr == jsonDocument.MemberEnd() || !typeItr->value.IsString() || azstricmp(typeItr->value.GetString(), FileType) != 0)
        {
            return AZ::Failure(AZStd::string::format("Not a valid JsonSerialization file"));
        }

        auto nameItr = jsonDocument.FindMember(ClassNameTag);
        if (nameItr == jsonDocument.MemberEnd() || !nameItr->value.IsString())
        {
            return AZ::Failure(AZStd::string::format("File should contain ClassName"));
        }

        auto dataItr = jsonDocument.FindMember(ClassDataTag);
        // data can be empty but it should be an object
        if (dataItr != jsonDocument.MemberEnd() && !dataItr->value.IsObject())
        {
            return AZ::Failure(AZStd::string::format("ClassData should be an object"));
        }

        return AZ::Success();
    }