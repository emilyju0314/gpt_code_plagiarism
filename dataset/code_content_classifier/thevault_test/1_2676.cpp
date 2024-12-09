int gjAPI::gjInterScore::__CheckCache(gjScoreTableMap* papOutput)
{
    // retrieve cached score tables
    if(m_apScoreTable.size() > 1)
    {
        if(papOutput)
        {
            FOR_EACH(it, m_apScoreTable)
                if(it->first) (*papOutput)[it->first] = it->second;
        }
        return GJ_OK;
    }
    return GJ_NO_DATA_FOUND;
}