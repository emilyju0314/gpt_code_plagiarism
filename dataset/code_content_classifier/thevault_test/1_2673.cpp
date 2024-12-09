void gjAPI::gjInterTrophy::__LoadOffCache()
{
    if(!GJ_API_OFFCACHE_TROPHY) return;
    if(m_iCache != 0) return;

    // open cache file
    std::FILE* pFile = std::fopen(GJ_API_OFFCACHE_NAME, "r");
    if(pFile)
    {
        // read trophy header
        char acHeader[32];
        std::fscanf(pFile, "%31[^\n]%*c", acHeader);

        // read trophy data
        std::string sData;
        while(true)
        {
            char acLine[1024];
            std::fscanf(pFile, "%1023[^\n]%*c", acLine);
            if(std::feof(pFile)) break;

            if(std::strlen(acLine) > 1)
            {
                sData += acLine;
                sData += '\n';
            }
        }

        // close cache file
        std::fclose(pFile);

        if(!sData.empty())
        {
            // flag offline caching and load offline-cached trophies
            m_iCache = 1;
            this->__Process(sData, NULL, NULL);
        }
    }
}