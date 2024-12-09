bool AnimGraphManager::RemoveAnimGraph(AnimGraph* animGraph, bool delFromMemory)
    {
        MCore::LockGuardRecursive lock(m_animGraphLock);

        // find the index of the anim graph and return false in case the pointer is not valid
        const size_t animGraphIndex = FindAnimGraphIndex(animGraph);
        if (animGraphIndex == InvalidIndex)
        {
            return false;
        }

        RemoveAnimGraph(animGraphIndex, delFromMemory);
        return true;
    }