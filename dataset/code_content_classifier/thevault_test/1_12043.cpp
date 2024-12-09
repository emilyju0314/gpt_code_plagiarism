size_t MotionManager::CalcNumRootMotionSets() const
    {
        size_t result = 0;

        // get the number of motion sets and iterate through them
        for (const MotionSet* motionSet : m_motionSets)
        {
            // sum up the root motion sets
            if (motionSet->GetParentSet() == nullptr)
            {
                result++;
            }
        }

        return result;
    }