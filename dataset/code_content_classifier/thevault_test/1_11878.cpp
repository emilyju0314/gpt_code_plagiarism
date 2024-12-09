XmlNodeRef SafeLoadXmlFromFile(const AZStd::string& xmlPath)
    {
        if (gEnv->pCryPak->IsFileExist(xmlPath.c_str()))
        {
            return GetISystem()->LoadXmlFromFile(xmlPath.c_str());
        }

        return XmlNodeRef();
    }