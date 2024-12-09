MotionInstance* MotionSystem::CreateMotionInstance(Motion* motion, PlayBackInfo* info)
    {
        // create the motion instance
        MotionInstance* motionInst = GetMotionInstancePool().RequestNew(motion, m_actorInstance);

        // initialize the motion instance from the playback info settings
        motionInst->InitFromPlayBackInfo(*info);

        return motionInst;
    }