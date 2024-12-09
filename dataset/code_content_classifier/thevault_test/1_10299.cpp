void
    SoundManager::loadFutureBufferData(SoundData& rSoundData)
    {
        rSoundData.m_futureBufferData = std::async([&rSoundData]()
                                                   {
                                                       return rSoundData.m_soundBufferIO.readNextBuffer();
                                                   });
    }