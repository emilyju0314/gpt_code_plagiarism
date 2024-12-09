bool AnimGraphManager::RemoveAnimGraphInstance(AnimGraphInstance* animGraphInstance, bool delFromMemory)
    {
        MCore::LockGuardRecursive lock(m_animGraphInstanceLock);

        // find the index of the anim graph instance and return false in case the pointer is not valid
        const size_t instanceIndex = FindAnimGraphInstanceIndex(animGraphInstance);
        if (instanceIndex == InvalidIndex)
        {
            return false;
        }

        // remove the anim graph instance and return success
        RemoveAnimGraphInstance(instanceIndex, delFromMemory);
        return true;
    }