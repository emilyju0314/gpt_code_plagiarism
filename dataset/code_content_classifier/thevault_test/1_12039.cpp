bool MotionManager::RemoveMotionWithoutLock(size_t index, bool delFromMemory)
    {
        if (index == InvalidIndex)
        {
            return false;
        }

        Motion* motion = m_motions[index];

        // stop all motion instances of the motion to delete
        const size_t numActorInstances = GetActorManager().GetNumActorInstances();
        for (size_t i = 0; i < numActorInstances; ++i)
        {
            ActorInstance* actorInstance = GetActorManager().GetActorInstance(i);
            MotionSystem* motionSystem = actorInstance->GetMotionSystem();
            MCORE_ASSERT(actorInstance->GetMotionSystem());

            // instances and iterate through the motion instances
            for (size_t j = 0; j < motionSystem->GetNumMotionInstances(); )
            {
                MotionInstance* motionInstance = motionSystem->GetMotionInstance(j);

                // only stop instances that belong to our motion we want to remove
                if (motionInstance->GetMotion() == motion)
                {
                    // stop the motion instance and remove it directly from the motion system
                    motionInstance->Stop(0.0f);
                    actorInstance->GetMotionSystem()->RemoveMotionInstance(motionInstance);
                }
                else
                {
                    j++;
                }
            }
        }

        // Reset all motion entries in the motion sets of the current motion.
        for (const MotionSet* motionSet : m_motionSets)
        {
            const EMotionFX::MotionSet::MotionEntries& motionEntries = motionSet->GetMotionEntries();
            for (const auto& item : motionEntries)
            {
                EMotionFX::MotionSet::MotionEntry* motionEntry = item.second;

                if (motionEntry->GetMotion() == motion)
                {
                    motionEntry->Reset();
                }
            }
        }

        // stop all motion instances of the motion to delete inside the motion nodes and reset their unique data
        const size_t numAnimGraphs = GetAnimGraphManager().GetNumAnimGraphs();
        for (size_t i = 0; i < numAnimGraphs; ++i)
        {
            AnimGraph* animGraph = GetAnimGraphManager().GetAnimGraph(i);
            ResetMotionNodes(animGraph, motion);
        }

        if (delFromMemory)
        {
            // destroy the memory of the motion, the destructor of the motion internally calls MotionManager::RemoveMotion(this)
            // which unregisters the motion from the motion manager
            motion->SetAutoUnregister(false);
            motion->Destroy();
            m_motions.erase(AZStd::next(begin(m_motions), index)); // only remove the motion from the motion manager without destroying its memory
        }
        else
        {
            m_motions.erase(AZStd::next(begin(m_motions), index)); // only remove the motion from the motion manager without destroying its memory
        }

        return true;
    }