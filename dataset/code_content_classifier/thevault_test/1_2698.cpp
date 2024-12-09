int gjDataItem::__RemoveCallback(const std::string& sData, void* pAdd, gjDataItemPtr* ppOutput)
{
    // parse output (only check status)
    gjDataList aaReturn;
    if(m_pAPI->ParseRequestKeypair(sData, &aaReturn) != GJ_OK)
    {
        gjAPI::ErrorLogAdd("API Error: could not parse data store item");
        return GJ_REQUEST_FAILED;
    }

    if(ppOutput) (*ppOutput) = this;
    return GJ_OK;
}