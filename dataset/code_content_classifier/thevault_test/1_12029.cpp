Motion* MotionManager::FindMotionByID(uint32 id) const
    {
        const auto foundMotion = AZStd::find_if(begin(m_motions), end(m_motions), [id](const Motion* motion)
        {
            return motion->GetID() == id;
        });
        return foundMotion != end(m_motions) ? *foundMotion : nullptr;
    }