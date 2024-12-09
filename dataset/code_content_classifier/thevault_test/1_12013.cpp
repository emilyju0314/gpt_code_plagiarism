void ProjectSettingsContainer::LoadPlist(PlistSettings& plistSettings)
    {
        StringOutcome outcome = ReadConfigFile(plistSettings.m_path, plistSettings.m_rawData);
        if (!outcome.IsSuccess())
        {
            m_errors.push(SettingsError(GetFailedLoadingPlistText(), outcome.GetError()));
        }

        plistSettings.m_document->parse<xmlFlags>(plistSettings.m_rawData.data());
    }