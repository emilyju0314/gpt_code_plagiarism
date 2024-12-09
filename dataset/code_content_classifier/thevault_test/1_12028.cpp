size_t MotionManager::FindMotionIndexByID(uint32 id) const
    {
        const auto foundMotion = AZStd::find_if(begin(m_motions), end(m_motions), [id](const Motion* motion)
        {
            return motion->GetID() == id;
        });
        return foundMotion != end(m_motions) ? AZStd::distance(begin(m_motions), foundMotion) : InvalidIndex;
        // get the number of motions and iterate through them
    }