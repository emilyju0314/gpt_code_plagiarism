void gjAPI::gjInterTrophy::__SaveOffCache(const std::string& sData)
{
    if(!GJ_API_OFFCACHE_TROPHY) return;
    if(m_iCache != 0) return;

    // open cache file
    std::FILE* pFile = std::fopen(GJ_API_OFFCACHE_NAME, "w");
    if(pFile)
    {
        // write data and close cache file
        std::fputs("[TROPHY]\n", pFile);
        std::fputs(sData.c_str(), pFile);
        std::fclose(pFile);
    }
}