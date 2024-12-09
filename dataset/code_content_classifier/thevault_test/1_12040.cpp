bool MotionManager::RemoveMotionSetWithoutLock(size_t index, bool delFromMemory)
    {
        if (index == InvalidIndex)
        {
            return false;
        }

        MotionSet* motionSet = m_motionSets[index];

        // remove from the parent
        MotionSet* parentSet = motionSet->GetParentSet();
        if (parentSet)
        {
            parentSet->RemoveChildSetByID(motionSet->GetID());
        }

        // reset all anim graph instance motion sets that use the motion set to delete
        const size_t numAnimGraphInstances = GetAnimGraphManager().GetNumAnimGraphInstances();
        for (size_t i = 0; i < numAnimGraphInstances; ++i)
        {
            AnimGraphInstance* animGraphInstance = GetAnimGraphManager().GetAnimGraphInstance(i);
            if (animGraphInstance->GetMotionSet() == motionSet)
            {
                animGraphInstance->SetMotionSet(nullptr);
            }
        }

        if (delFromMemory)
        {
            motionSet->SetAutoUnregister(false);
            delete motionSet;
        }

        m_motionSets.erase(AZStd::next(begin(m_motionSets), index));

        return true;
    }