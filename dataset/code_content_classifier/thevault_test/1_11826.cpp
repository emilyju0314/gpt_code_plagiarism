MotionInstance* MotionLayerSystem::FindFirstNonMixingMotionInstance() const
    {
        // if there aren't any motion instances, return nullptr
        const auto foundMotionInstance = AZStd::find_if(begin(m_motionInstances), end(m_motionInstances), [](const MotionInstance* motionInstance)
        {
            return !motionInstance->GetIsMixing();
        });
        return foundMotionInstance != end(m_motionInstances) ? *foundMotionInstance : nullptr;
    }