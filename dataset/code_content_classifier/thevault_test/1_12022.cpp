Motion* MotionManager::FindMotionByName(const char* motionName, bool isTool) const
    {
        const auto foundMotion = AZStd::find_if(begin(m_motions), end(m_motions), [motionName, isTool](const auto& motion)
        {
            return motion->GetIsOwnedByRuntime() != isTool && motion->GetNameString() == motionName;
        });
        return foundMotion != end(m_motions) ? *foundMotion : nullptr;
    }