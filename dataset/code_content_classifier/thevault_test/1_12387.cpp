bool Importer::ProcessChunk(MCore::File* file, ImportParameters& importParams)
    {
        // if we have reached the end of the file, exit
        if (file->GetIsEOF())
        {
            return false;
        }

        // try to read the chunk header
        FileFormat::FileChunk chunk;
        if (!file->Read(&chunk, sizeof(FileFormat::FileChunk)))
        {
            return false; // failed reading chunk
        }
        // convert endian
        const MCore::Endian::EEndianType endianType = importParams.m_endianType;
        MCore::Endian::ConvertUnsignedInt32(&chunk.m_chunkId, endianType);
        MCore::Endian::ConvertUnsignedInt32(&chunk.m_sizeInBytes, endianType);
        MCore::Endian::ConvertUnsignedInt32(&chunk.m_version, endianType);

        // try to find the chunk processor which can process this chunk
        ChunkProcessor* processor = FindChunk(chunk.m_chunkId, chunk.m_version);

        // if we cannot find the chunk, skip the chunk
        if (processor == nullptr)
        {
            if (GetLogging())
            {
                MCore::LogError("Importer::ProcessChunk() - Unknown chunk (ID=%d  Size=%d bytes Version=%d), skipping...", chunk.m_chunkId, chunk.m_sizeInBytes, chunk.m_version);
            }
            file->Forward(chunk.m_sizeInBytes);

            return true;
        }

        // get some shortcuts
        Importer::ActorSettings* actorSettings = importParams.m_actorSettings;
        Importer::MotionSettings* skelMotionSettings = importParams.m_motionSettings;

        // check if we still want to skip the chunk or not
        bool mustSkip = false;

        // check if we specified to ignore this chunk
        if (actorSettings && AZStd::find(begin(actorSettings->m_chunkIDsToIgnore), end(actorSettings->m_chunkIDsToIgnore), chunk.m_chunkId) != end(actorSettings->m_chunkIDsToIgnore))
        {
            mustSkip = true;
        }

        if (skelMotionSettings && AZStd::find(begin(skelMotionSettings->m_chunkIDsToIgnore), end(skelMotionSettings->m_chunkIDsToIgnore), chunk.m_chunkId) != end(skelMotionSettings->m_chunkIDsToIgnore))
        {
            mustSkip = true;
        }

        // if we still don't need to skip
        if (mustSkip == false)
        {
            // if we're loading an actor
            if (actorSettings)
            {
                if ((actorSettings->m_loadLimits                 == false && chunk.m_chunkId == FileFormat::ACTOR_CHUNK_LIMIT) ||
                    (actorSettings->m_loadMorphTargets           == false && chunk.m_chunkId == FileFormat::ACTOR_CHUNK_STDPROGMORPHTARGET) ||
                    (actorSettings->m_loadMorphTargets           == false && chunk.m_chunkId == FileFormat::ACTOR_CHUNK_STDPMORPHTARGETS) ||
                    (actorSettings->m_loadSimulatedObjects       == false && chunk.m_chunkId == FileFormat::ACTOR_CHUNK_SIMULATEDOBJECTSETUP))
                {
                    mustSkip = true;
                }
            }

            // if we're loading a motion
            if (skelMotionSettings)
            {
                if (skelMotionSettings->m_loadMotionEvents       == false && chunk.m_chunkId == FileFormat::MOTION_CHUNK_MOTIONEVENTTABLE)
                {
                    mustSkip = true;
                }
            }
        }

        // if we want to skip this chunk
        if (mustSkip)
        {
            file->Forward(chunk.m_sizeInBytes);
            return true;
        }

        // try to process the chunk
        return processor->Process(file, importParams);
    }