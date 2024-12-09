void
    SoundManager::update()
    {
        for (auto& rSoundData : m_soundMap)
        {
            if (rSoundData.second.m_status != ESoundStatus::Playing ||
                !rSoundData.second.m_pSourceData)
                continue;

            // Find buffers to dequeue
            int buffersProcessed = 0;
            alGetSourcei(rSoundData.second.m_pSourceData->m_sourceId, AL_BUFFERS_PROCESSED, &buffersProcessed);
            printAlError();

            if (buffersProcessed > 0)
            {
                // Dequeue processed buffers
                std::vector<unsigned int> unqueuedBufferIds(buffersProcessed, 0);
                alSourceUnqueueBuffers(rSoundData.second.m_pSourceData->m_sourceId, buffersProcessed, unqueuedBufferIds.data());
                printAlError();

                // Load the asynchronously loaded data chunk into a buffer and queue the buffer
                if (rSoundData.second.m_futureBufferData.valid())
                    queueBuffer(rSoundData.second, rSoundData.second.m_futureBufferData.get());

                if (rSoundData.second.m_soundBufferIO.hasReachedEnd() &&
                    !rSoundData.second.m_soundBufferIO.isLoopEnabled())
                {
                    // If the complete sound has been loaded, check if there are still buffers queued ...
                    int buffersQueued = 0;
                    alGetSourcei(rSoundData.second.m_pSourceData->m_sourceId, AL_BUFFERS_QUEUED, &buffersQueued);
                    printAlError();

                    // ... If not, stop the playback ...
                    if (buffersQueued == 0)
                    {
                        alSourceStop(rSoundData.second.m_pSourceData->m_sourceId);
                        printAlError();

                        rSoundData.second.m_status = ESoundStatus::Stopped;

                        // ... and prepare for next playback
                        preloadBuffers(rSoundData.second);
                    }
                }
                else
                {
                    // If the sound is not completely loaded yet, load more buffers and queue them
                    for (int i = 0; i < buffersProcessed - 1 && (!rSoundData.second.m_soundBufferIO.hasReachedEnd() || rSoundData.second.m_soundBufferIO.isLoopEnabled()); ++i)
                        queueNextBuffer(rSoundData.second);
                    if (!rSoundData.second.m_soundBufferIO.hasReachedEnd() || rSoundData.second.m_soundBufferIO.isLoopEnabled())
                        loadFutureBufferData(rSoundData.second);
                }
            }
        }
    }