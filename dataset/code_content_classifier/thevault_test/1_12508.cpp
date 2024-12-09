size_t GetMorphTargetChunkSize(EMotionFX::MorphTarget* inputMorphTarget)
    {
        MCORE_ASSERT(inputMorphTarget->GetType() == EMotionFX::MorphTargetStandard::TYPE_ID);
        EMotionFX::MorphTargetStandard* morphTarget = (EMotionFX::MorphTargetStandard*)inputMorphTarget;

        size_t totalSize = 0;
        totalSize += sizeof(EMotionFX::FileFormat::Actor_MorphTarget);
        totalSize += GetStringChunkSize(morphTarget->GetName());
        totalSize += sizeof(EMotionFX::FileFormat::Actor_MorphTargetTransform) * morphTarget->GetNumTransformations();

        return totalSize;
    }