int gjAPI::__LoginCallback(const std::string& sData, void* pAdd, int* pbOutput)
{
    // check for success
    gjDataList aaReturn;
    if(this->ParseRequestKeypair(sData, &aaReturn) != GJ_OK)
    {
        gjAPI::ErrorLogAdd("API Error: could not authenticate user <" + m_sUserName + ">");

        // clear main user data
        m_sUserName      = "";
        m_sUserToken     = "";
        m_sProcUserName  = "";
        m_sProcUserToken = "";

        // determine error type
        const int iError = std::strcmp(SAFE_MAP_GET(aaReturn[0], "success").c_str(), "false") ? GJ_NETWORK_ERROR : GJ_REQUEST_FAILED;

        if(pbOutput) (*pbOutput) = iError;
        return pbOutput ? GJ_OK : iError;
    }

    // set connection
    m_bConnected = true;

    // open the user session
    if(pAdd) this->__OpenSession();

    // prefetch user data
    if(GJ_API_PREFETCH)
    {
        m_pInterUser->FetchUserCall(0, GJ_NETWORK_NULL_THIS(gjUserPtr));
        m_pInterTrophy->FetchTrophiesCall(0, GJ_NETWORK_NULL_THIS(gjTrophyList));
        m_pInterDataStoreUser->FetchDataItemsCall(GJ_NETWORK_NULL_THIS(gjDataItemMap));
    }

    if(pbOutput) (*pbOutput) = GJ_OK;
    return GJ_OK;
}