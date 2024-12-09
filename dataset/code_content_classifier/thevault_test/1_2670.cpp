gjTrophy* gjAPI::gjInterTrophy::GetTrophy(const int iID)
{
    if(!m_pAPI->IsUserConnected() && m_iCache == 0) return m_apTrophy[0];
    if(m_apTrophy.size() <= 1)
    {
        // wait for prefetching
        if(GJ_API_PREFETCH) m_pNetwork->Wait(2);
        if(m_apTrophy.size() <= 1)
        {
            gjTrophyList apOutput;
            this->FetchTrophiesNow(0, &apOutput);
        }
    }
    return m_apTrophy.count(iID) ? m_apTrophy[iID] : m_apTrophy[0];
}