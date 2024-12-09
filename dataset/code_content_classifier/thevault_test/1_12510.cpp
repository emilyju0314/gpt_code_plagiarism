void SaveMorphTargets(MCore::Stream* file, EMotionFX::Actor* actor, size_t lodLevel, MCore::Endian::EEndianType targetEndianType)
    {
        MCORE_ASSERT(file);
        MCORE_ASSERT(actor);

        EMotionFX::MorphSetup* morphSetup = actor->GetMorphSetup(lodLevel);
        if (morphSetup == nullptr)
        {
            return;
        }

        // get the number of morph targets we need to save to the file and check if there are any at all
        const size_t numSavedMorphTargets = GetNumSavedMorphTargets(morphSetup);
        if (numSavedMorphTargets <= 0)
        {
            MCore::LogInfo("No morph targets to be saved in morph setup. Skipping writing morph targets.");
            return;
        }

        // get the number of morph targets
        const size_t numMorphTargets = morphSetup->GetNumMorphTargets();

        // check if all morph targets have a valid name and rename them in case they are empty
        for (size_t i = 0; i < numMorphTargets; ++i)
        {
            EMotionFX::MorphTarget* morphTarget = morphSetup->GetMorphTarget(i);

            // check if the name of the morph target is valid
            if (morphTarget->GetNameString().empty())
            {
                // rename the morph target
                AZStd::string morphTargetName;
                morphTargetName = AZStd::string::format("Morph Target %zu", MCore::GetIDGenerator().GenerateID());
                MCore::LogWarning("The morph target has an empty name. The morph target will be automatically renamed to '%s'.", morphTargetName.c_str());
                morphTarget->SetName(morphTargetName.c_str());
            }
        }

        // fill in the chunk header
        EMotionFX::FileFormat::FileChunk chunkHeader;
        chunkHeader.m_chunkId        = EMotionFX::FileFormat::ACTOR_CHUNK_STDPMORPHTARGETS;
        chunkHeader.m_sizeInBytes    = aznumeric_caster(GetMorphSetupChunkSize(morphSetup));
        chunkHeader.m_version        = 2;

        // endian convert the chunk and write it to the file
        ConvertFileChunk(&chunkHeader, targetEndianType);
        file->Write(&chunkHeader, sizeof(EMotionFX::FileFormat::FileChunk));

        // fill in the chunk header
        EMotionFX::FileFormat::Actor_MorphTargets morphTargetsChunk;
        morphTargetsChunk.m_numMorphTargets  = aznumeric_caster(numSavedMorphTargets);
        morphTargetsChunk.m_lod              = aznumeric_caster(lodLevel);

        MCore::LogDetailedInfo("============================================================");
        MCore::LogInfo("Morph Targets (%i, LOD=%d)", morphTargetsChunk.m_numMorphTargets, morphTargetsChunk.m_lod);
        MCore::LogDetailedInfo("============================================================");

        // endian convert the chunk and write it to the file
        ConvertUnsignedInt(&morphTargetsChunk.m_numMorphTargets, targetEndianType);
        ConvertUnsignedInt(&morphTargetsChunk.m_lod, targetEndianType);
        file->Write(&morphTargetsChunk, sizeof(EMotionFX::FileFormat::Actor_MorphTargets));

        // save morph targets
        for (size_t i = 0; i < numMorphTargets; ++i)
        {
            SaveMorphTarget(file, actor, morphSetup->GetMorphTarget(i), lodLevel, targetEndianType);
        }
    }