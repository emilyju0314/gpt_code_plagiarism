void
    SoundManager::createSound(String const& rName, bool loopEnabled)
    {
        if (m_nextSourceIndex >= m_sourceCount)
            throw std::exception(String("Sound error: Unable to create sound '%'. Buffers full").arg(rName).c_str());

        auto const [itSoundData, ok] = m_soundMap.emplace(rName,
                                                          SoundData(String("resource/%.wav").arg(rName),
                                                                    m_bufferByteSize));

        if (!ok)
            throw std::exception(String("Sound error: Unable to create sound '%'. Already exists").arg(rName).c_str());

        itSoundData->second.m_pSourceData = &m_sourceData[m_nextSourceIndex];
        itSoundData->second.m_soundBufferIO.setLoopEnabled(loopEnabled);
        preloadBuffers(itSoundData->second);

        ++m_nextSourceIndex;
    }