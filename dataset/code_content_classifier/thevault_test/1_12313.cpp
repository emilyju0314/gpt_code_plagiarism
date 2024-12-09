AnimGraph* AnimGraphManager::FindAnimGraphByID(uint32 animGraphID) const
    {
        MCore::LockGuardRecursive lock(m_animGraphLock);

        for (EMotionFX::AnimGraph* animGraph : m_animGraphs)
        {
            if (animGraph->GetID() == animGraphID)
            {
                return animGraph;
            }
        }

        return nullptr;
    }