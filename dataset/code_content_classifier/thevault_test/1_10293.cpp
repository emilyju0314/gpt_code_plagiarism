void
    SoundManager::initialize()
    {
        // Setup audio device and context if necessary
        if (!sm_pDevice)
        {
            sm_pDevice = alcOpenDevice(0);
            printAlError();
            if (!sm_pDevice)
                throw std::exception("Sound error: Unable to open sound device");

            sm_pContext = alcCreateContext(sm_pDevice, 0);
            printAlError();
            alcMakeContextCurrent(sm_pContext);
            printAlError();
        }

        // Setup sources and their dedicated buffers
        m_sourceData.reserve(m_sourceCount);
        for (size_t i = 0; i < m_sourceCount; ++i)
        {
            auto& rSourceData = m_sourceData.emplace_back();
            rSourceData.m_bufferIds.resize(m_buffersPerSource);
            alGenBuffers(static_cast<ALsizei>(rSourceData.m_bufferIds.size()), rSourceData.m_bufferIds.data());
            printAlError();
            alGenSources(1, &rSourceData.m_sourceId);
            printAlError();

            // Deactivate looping (looping is done by SoundManager)
            alSourcei(rSourceData.m_sourceId, AL_LOOPING, false);
            printAlError();
        }
    }