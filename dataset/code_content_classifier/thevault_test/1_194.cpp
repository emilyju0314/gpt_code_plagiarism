TPtrC CSmsMtmSettings::GetDefaultScNumberL() const
    {
    // check if default SC is set
    const CSmsSettings& smsSettings = iSmsMtm->ServiceSettings();
    if (!smsSettings.ServiceCenterCount())
        {
        User::Leave(KErrNotFound);
        }
    
    TInt scDefaultIndex = smsSettings.DefaultServiceCenter();

    return smsSettings.GetServiceCenter(scDefaultIndex).Address();
    }