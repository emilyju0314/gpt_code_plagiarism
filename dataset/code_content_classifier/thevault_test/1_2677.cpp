int gjAPI::gjInterScore::__Process(const std::string& sData, void* pAdd, gjScoreTableMap* papOutput)
{
    // parse output
    gjDataList aaReturn;
    if(m_pAPI->ParseRequestKeypair(sData, &aaReturn) != GJ_OK)
    {
        gjAPI::ErrorLogAdd("API Error: could not parse score tables");
        return GJ_REQUEST_FAILED;
    }

    // create and cache score tables
    FOR_EACH(it, aaReturn)
    {
        gjScoreTable* pNewScoreTable = new gjScoreTable(*it, m_pAPI);
        const int iID = pNewScoreTable->GetID();

        if(m_apScoreTable.count(iID)) SAFE_DELETE(pNewScoreTable)
        else m_apScoreTable[iID] = pNewScoreTable;
    }

    return (this->__CheckCache(papOutput) == GJ_OK) ? GJ_OK : GJ_NO_DATA_FOUND;
}