void MotionSystem::StopAllMotions(Motion* motion)
    {
        for (MotionInstance* motionInstance : m_motionInstances)
        {
            if (motionInstance->GetMotion()->GetID() == motion->GetID())
            {
                motionInstance->Stop();
            }
        }
    }