int gjDataItem::__GetDataCallback(const std::string& sData, void* pAdd, std::string* psOutput)
{
    // parse output
    std::string sReturn;
    if(m_pAPI->ParseRequestDump(sData, &sReturn) != GJ_OK)
    {
        gjAPI::ErrorLogAdd("API Error: could not parse data store item");
        return GJ_REQUEST_FAILED;
    }

    // save data
    m_sData = sReturn;

    if(psOutput) (*psOutput) = m_sData;
    return GJ_OK;
}