MotionSet* MotionManager::FindRootMotionSet(size_t index)
    {
        auto foundRootMotionSet = AZStd::find_if(begin(m_motionSets), end(m_motionSets), [iter = index](const MotionSet* motionSet) mutable
        {
            return motionSet->GetParentSet() == nullptr && iter-- == 0;
        });
        return foundRootMotionSet != end(m_motionSets) ? *foundRootMotionSet : nullptr;
    }