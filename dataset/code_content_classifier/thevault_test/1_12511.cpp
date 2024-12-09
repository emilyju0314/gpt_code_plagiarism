void SaveMorphTargets(MCore::Stream* file, EMotionFX::Actor* actor, MCore::Endian::EEndianType targetEndianType)
    {
        // get the number of LOD levels and save the morph targets for each
        const size_t numLODLevels = actor->GetNumLODLevels();
        for (size_t i = 0; i < numLODLevels; ++i)
        {
            SaveMorphTargets(file, actor, i, targetEndianType);
        }
    }