MotionSet* MotionManager::FindMotionSetByFileName(const char* fileName, bool isTool) const
    {
        const auto foundMotionSet = AZStd::find_if(begin(m_motionSets), end(m_motionSets), [fileName, isTool](const auto& motionSet)
        {
            return motionSet->GetIsOwnedByRuntime() != isTool &&
                AzFramework::StringFunc::Equal(motionSet->GetFilename(), fileName);
        });
        return foundMotionSet != end(m_motionSets) ? *foundMotionSet : nullptr;
    }