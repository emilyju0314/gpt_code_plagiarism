bool MotionSystem::CheckIfIsPlayingMotion(Motion* motion, bool ignorePausedMotions) const
    {
        return motion && AZStd::any_of(begin(m_motionInstances), end(m_motionInstances), [motion, ignorePausedMotions](const MotionInstance* motionInstance)
        {
            return !(ignorePausedMotions && motionInstance->GetIsPaused()) &&
                motionInstance->GetMotion()->GetID() == motion->GetID();
        });
    }