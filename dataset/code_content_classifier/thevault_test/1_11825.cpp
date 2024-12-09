size_t MotionLayerSystem::RemoveLayersBelow(MotionInstance* source)
    {
        size_t numRemoved = 0;

        // start from the bottom up
        for (auto iter = rbegin(m_motionInstances); iter != rend(m_motionInstances); ++iter)
        {
            MotionInstance* curInstance = *iter;

            // if we reached the current motion instance we are done
            if (curInstance == source)
            {
                return numRemoved;
            }

            numRemoved++;
            RemoveMotionInstance(curInstance);
        }

        return numRemoved;
    }