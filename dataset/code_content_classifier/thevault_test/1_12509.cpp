size_t GetMorphSetupChunkSize(EMotionFX::MorphSetup* morphSetup)
    {
        // get the number of morph targets
        const size_t numMorphTargets = morphSetup->GetNumMorphTargets();

        // calculate the size of the chunk
        size_t totalSize = sizeof(EMotionFX::FileFormat::Actor_MorphTargets);
        for (size_t i = 0; i < numMorphTargets; ++i)
        {
            totalSize += GetMorphTargetChunkSize(morphSetup->GetMorphTarget(i));
        }

        return totalSize;
    }