Motion* MotionManager::FindMotionByFileName(const char* fileName, bool isTool) const
    {
        const auto foundMotion = AZStd::find_if(begin(m_motions), end(m_motions), [fileName, isTool](const auto& motion)
        {
            return motion->GetIsOwnedByRuntime() != isTool &&
                AzFramework::StringFunc::Equal(motion->GetFileNameString().c_str(), fileName, false /* no case */);
        });
        return foundMotion != end(m_motions) ? *foundMotion : nullptr;
    }