int gjScoreTable::__AddScoreCallback(const std::string& sData, void* pAdd, gjScorePtr* pOutput)
{
    gjScore* pNewScore = static_cast<gjScore*>(pAdd);

    // remove score entry from verification list
    FOR_EACH(it, m_apVerify)
    {
        if((*it) == pNewScore)
        {
            m_apVerify.erase(it);
            break;
        }
    }

    // cache score entry
    m_apScore.push_back(pNewScore);

    // sort score entries
    if(m_iSortDir) std::sort(m_apScore.begin(), m_apScore.end(), (m_iSortDir == GJ_SORT_DESC) ? SortDescending : SortAscending);

    if(pOutput) (*pOutput) = pNewScore;
    return GJ_OK;
}