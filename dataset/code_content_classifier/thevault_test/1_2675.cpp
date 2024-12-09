void gjAPI::gjInterScore::ClearCache()
{
    // save NULL score table
    gjScoreTable* pNull = m_apScoreTable[0]; m_apScoreTable.erase(0);

    // delete score tables and scores entries
    FOR_EACH(it, m_apScoreTable)
        SAFE_DELETE(it->second)

    // clear container
    m_apScoreTable.clear();
    m_apScoreTable[0] = pNull;
}