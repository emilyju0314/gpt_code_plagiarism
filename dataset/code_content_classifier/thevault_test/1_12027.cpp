size_t MotionManager::FindMotionSetIndexByName(const char* name, bool isTool) const
    {
        const auto foundMotionSet = AZStd::find_if(begin(m_motionSets), end(m_motionSets), [name, isTool](const MotionSet* motionSet)
        {
            return motionSet->GetIsOwnedByRuntime() != isTool &&
                AzFramework::StringFunc::Equal(motionSet->GetName(), name);
        });
        return foundMotionSet != end(m_motionSets) ? AZStd::distance(begin(m_motionSets), foundMotionSet) : InvalidIndex;
    }