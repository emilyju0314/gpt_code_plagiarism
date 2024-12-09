size_t MotionManager::FindMotionSetIndex(MotionSet* motionSet) const
    {
        const auto foundMotionSet = AZStd::find_if(begin(m_motionSets), end(m_motionSets), [motionSet](const MotionSet* ms)
        {
            return ms == motionSet;
        });
        return foundMotionSet != end(m_motionSets) ? AZStd::distance(begin(m_motionSets), foundMotionSet) : InvalidIndex;
    }