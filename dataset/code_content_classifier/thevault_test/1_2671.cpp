int gjAPI::gjInterTrophy::__Process(const std::string& sData, void* pAdd, gjTrophyList* papOutput)
{
    // parse output
    gjDataList aaReturn;
    if(m_pAPI->ParseRequestKeypair(sData, &aaReturn) != GJ_OK)
    {
        gjAPI::ErrorLogAdd("API Error: could not parse trophies");
        return GJ_REQUEST_FAILED;
    }

    // offline-cache trophy data
    if(!aaReturn.empty()) this->__SaveOffCache(sData);
    if(m_iCache == 0) m_iCache = 2;

    // create and cache trophy objects
    FOR_EACH(it, aaReturn)
    {
        gjTrophy* pNewTrophy = new gjTrophy(*it, m_pAPI);
        const int iID = pNewTrophy->GetID();

        if(m_apTrophy.count(iID))
        {
            *m_apTrophy[iID] = *pNewTrophy;
            SAFE_DELETE(pNewTrophy)
        }
        else m_apTrophy[iID] = pNewTrophy;
    }

    // apply attributes
    this->SetSort  (NULL, 0);
    this->SetSecret(NULL, 0);
    this->SetHidden(NULL, 0);

    return (this->__CheckCache(P_TO_I(pAdd), papOutput) == GJ_OK) ? GJ_OK : GJ_NO_DATA_FOUND;
}