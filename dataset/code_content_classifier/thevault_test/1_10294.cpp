void
    SoundManager::cleanUp()
    {
        for (auto const& rSourceData : m_sourceData)
        {
            alDeleteSources(1, &rSourceData.m_sourceId);
            printAlError();
            alDeleteBuffers(static_cast<ALsizei>(rSourceData.m_bufferIds.size()), rSourceData.m_bufferIds.data());
            printAlError();
        }
        m_sourceData.clear();
        m_soundMap.clear();
    }