void AnimGraphManager::RemoveAnimGraph(size_t index, bool delFromMemory)
    {
        MCore::LockGuardRecursive lock(m_animGraphLock);

        AnimGraph* animGraph = m_animGraphs[index];
        const int animGraphInstanceCount = static_cast<int>(m_animGraphInstances.size());
        for (int i = animGraphInstanceCount - 1; i >= 0; --i)
        {
            if (m_animGraphInstances[i]->GetAnimGraph() == animGraph)
            {
                RemoveAnimGraphInstance(m_animGraphInstances[i]);
            }
        }

        // Need to remove it from the list of anim graphs first since deleting it can cause assets to get unloaded and
        // this function to be called recursively (making the index to shift)
        m_animGraphs.erase(m_animGraphs.begin() + index);

        if (delFromMemory)
        {
            // Destroy the memory of the anim graph and disable auto-unregister so that  the destructor of the anim graph does not
            // internally call AnimGraphManager::RemoveAnimGraph(this, false) to unregister the anim graph from the anim graph manager.
            animGraph->SetAutoUnregister(false);
            delete animGraph;
        }
    }