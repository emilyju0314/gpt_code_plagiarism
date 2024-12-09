size_t MotionManager::FindMotionIndex(Motion* motion) const
    {
        const auto foundMotion = AZStd::find_if(begin(m_motions), end(m_motions), [motion](const Motion* m)
        {
            return m == motion;
        });
        return foundMotion != end(m_motions) ? AZStd::distance(begin(m_motions), foundMotion) : InvalidIndex;
    }