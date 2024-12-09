MotionSet* MotionManager::FindMotionSetByName(const char* name, bool isOwnedByRuntime) const
    {
        const auto foundMotionSet = AZStd::find_if(begin(m_motionSets), end(m_motionSets), [name, isOwnedByRuntime](const auto& motionSet)
        {
            return motionSet->GetIsOwnedByRuntime() == isOwnedByRuntime &&
                AzFramework::StringFunc::Equal(motionSet->GetName(), name);
        });
        return foundMotionSet != end(m_motionSets) ? *foundMotionSet : nullptr;
    }