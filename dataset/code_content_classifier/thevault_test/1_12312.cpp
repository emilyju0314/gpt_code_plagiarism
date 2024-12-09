AnimGraph* AnimGraphManager::FindAnimGraphByFileName(const char* filename, bool isTool) const
    {
        MCore::LockGuardRecursive lock(m_animGraphLock);

        for (EMotionFX::AnimGraph* animGraph : m_animGraphs)
        {
            if (animGraph->GetIsOwnedByRuntime() == isTool)
            {
                continue;
            }

            if (AzFramework::StringFunc::Equal(animGraph->GetFileName(), filename, false /* no case */))
            {
                return animGraph;
            }
        }

        return nullptr;
    }