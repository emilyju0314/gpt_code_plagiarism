void
    SoundManager::queueBuffer(SoundData& rSoundData,
                              std::vector<int16_t>&& rBufferData)
    {
        if (!rSoundData.m_pSourceData)
            return;

        alBufferData(rSoundData.m_pSourceData->m_bufferIds[rSoundData.m_nextBufferIndex],
                     AL_FORMAT_STEREO16,
                     rBufferData.data(),
                     static_cast<ALsizei>(rBufferData.size() * sizeof(int16_t)),
                     rSoundData.m_soundBufferIO.getSampleRate());
        printAlError();

        alSourceQueueBuffers(rSoundData.m_pSourceData->m_sourceId, 1, &rSoundData.m_pSourceData->m_bufferIds[rSoundData.m_nextBufferIndex]);
        printAlError();
        rSoundData.m_nextBufferIndex = (rSoundData.m_nextBufferIndex + 1) % m_buffersPerSource;
    }