size_t MotionLayerSystem::FindInsertPos(size_t priorityLevel) const
    {
        const auto* foundInsertPosition = AZStd::lower_bound(begin(m_motionInstances), end(m_motionInstances), priorityLevel, [](const MotionInstance* motionInstance, size_t level)
        {
            return motionInstance->GetPriorityLevel() < level;
        });
        return foundInsertPosition != end(m_motionInstances) ? AZStd::distance(begin(m_motionInstances), foundInsertPosition) : InvalidIndex;
    }