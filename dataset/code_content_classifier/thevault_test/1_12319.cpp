void MotionSystem::StopAllMotions()
    {
        for (MotionInstance* motionInstance : m_motionInstances)
        {
            motionInstance->Stop();
        }
    }