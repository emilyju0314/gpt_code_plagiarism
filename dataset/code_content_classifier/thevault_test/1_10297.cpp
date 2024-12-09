void
    SoundManager::queueNextBuffer(SoundData& rSoundData)
    {
        queueBuffer(rSoundData, rSoundData.m_soundBufferIO.readNextBuffer());
    }