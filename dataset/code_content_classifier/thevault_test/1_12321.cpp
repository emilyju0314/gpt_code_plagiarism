bool MotionSystem::CheckIfIsValidMotionInstance(MotionInstance* instance) const
    {
        return instance && AZStd::any_of(begin(m_motionInstances), end(m_motionInstances), [instance](const MotionInstance* motionInstance)
        {
            return motionInstance->GetID() == instance->GetID();
        });
    }