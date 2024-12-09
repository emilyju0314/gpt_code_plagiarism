void
    SoundManager::preloadBuffers(SoundData& rSoundData)
    {
        queueNextBuffer(rSoundData);
        for (size_t i = 1; i < m_buffersPerSource - 1 && (!rSoundData.m_soundBufferIO.hasReachedEnd() || rSoundData.m_soundBufferIO.isLoopEnabled()); ++i)
            queueNextBuffer(rSoundData);

        if (!rSoundData.m_soundBufferIO.hasReachedEnd() || rSoundData.m_soundBufferIO.isLoopEnabled())
            loadFutureBufferData(rSoundData);
    }