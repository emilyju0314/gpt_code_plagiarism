void
    SoundManager::playSound(String const& rName)
    {
        auto const itSound = m_soundMap.find(rName);
        if (itSound == m_soundMap.end())
            throw std::exception(String("Sound error: Unable to find sound '%'").arg(rName).c_str());

        if (!itSound->second.m_pSourceData)
            return;

        int state = 0;
        alGetSourcei(itSound->second.m_pSourceData->m_sourceId, AL_SOURCE_STATE, &state);
        printAlError();
        if (state == AL_PLAYING)
            return;

        alSourcePlay(itSound->second.m_pSourceData->m_sourceId);
        printAlError();

        itSound->second.m_status = ESoundStatus::Playing;
    }