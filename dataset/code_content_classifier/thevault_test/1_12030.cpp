MotionSet* MotionManager::FindMotionSetByID(uint32 id) const
    {
        const auto foundMotionSet = AZStd::find_if(begin(m_motionSets), end(m_motionSets), [id](const MotionSet* motionSet)
        {
            return motionSet->GetID() == id;
        });
        return foundMotionSet != end(m_motionSets) ? *foundMotionSet : nullptr;
    }