int gjAPI::ParseRequestKeypair(const std::string& sInput, gjDataList* paaOutput)
{
    if(!paaOutput) return GJ_INVALID_INPUT;

    gjData aData;
    std::istringstream sStream(sInput);
    std::string sToken;

    // loop through input string
    while(std::getline(sStream, sToken))
    {
        // remove redundant characters
        gjAPI::UtilTrimString(&sToken);
        if(sToken.empty()) continue;

        // separate key and value
        const size_t iPos        = sToken.find(':');
        const std::string sKey   = sToken.substr(0, iPos);
        const std::string sValue = sToken.substr(iPos + 2, sToken.length() - iPos - 3);

        // next data block on same key
        if(aData.count(sKey.c_str()))
        {
            paaOutput->push_back(aData);
            aData.clear();
        }

        // create key and save value
        aData[sKey.c_str()] = sValue;
    }

    // insert last data block and check size
    if(!aData.empty()) paaOutput->push_back(aData);
    if(paaOutput->empty())
    {
        paaOutput->push_back(aData);
        gjAPI::ErrorLogAdd("API Error: string parsing failed");
        return GJ_INVALID_INPUT;
    }

    // check for failed request
    if(paaOutput->front()["success"] != "true")
    {
        gjAPI::ErrorLogAdd("API Error: request was unsuccessful");
        gjAPI::ErrorLogAdd("API Error: " + paaOutput->front()["message"]);
        return GJ_REQUEST_FAILED;
    }

    return GJ_OK;
}