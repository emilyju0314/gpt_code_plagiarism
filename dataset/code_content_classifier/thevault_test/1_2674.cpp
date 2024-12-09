gjScoreTable* gjAPI::gjInterScore::GetScoreTable(const int iID)
{
    if(m_apScoreTable.size() <= 1)
    {
        // wait for prefetching
        if(GJ_API_PREFETCH) m_pNetwork->Wait(2);
        if(m_apScoreTable.size() <= 1)
        {
            gjScoreTableMap apOutput;
            this->FetchScoreTablesNow(&apOutput);
        }
    }
    gjScoreTable* pPrimary = gjScoreTable::GetPrimary();
    return iID ? (m_apScoreTable.count(iID) ? m_apScoreTable[iID] : m_apScoreTable[0]) : (pPrimary ? pPrimary : m_apScoreTable[0]);
}