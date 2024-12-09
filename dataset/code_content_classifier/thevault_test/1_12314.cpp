AnimGraph* AnimGraphManager::GetFirstAnimGraph() const
    {
        MCore::LockGuardRecursive lock(m_animGraphLock);

        if (m_animGraphs.size() > 0)
        {
            return m_animGraphs[0];
        }
        return nullptr;
    }