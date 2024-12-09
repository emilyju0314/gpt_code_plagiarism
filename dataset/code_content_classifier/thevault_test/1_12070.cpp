TimeViewPlugin::MotionInfo* TimeViewPlugin::FindMotionInfo(uint32 motionID)
    {
        const auto foundMotionInfo = AZStd::find_if(begin(m_motionInfos), end(m_motionInfos), [motionID](const MotionInfo* motionInfo)
        {
            return motionInfo->m_motionId == motionID;
        });
        if (foundMotionInfo != end(m_motionInfos))
        {
            return *foundMotionInfo;
        }

        // we haven't found a motion info for the given id yet, so create a new one
        MotionInfo* motionInfo  = new MotionInfo();
        motionInfo->m_motionId   = motionID;
        motionInfo->m_initialized = false;
        m_motionInfos.emplace_back(motionInfo);
        return motionInfo;
    }