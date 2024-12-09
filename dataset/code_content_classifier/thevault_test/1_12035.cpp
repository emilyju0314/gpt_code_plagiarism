bool MotionManager::RemoveMotionSetByName(const char* motionName, bool delFromMemory, bool isTool)
    {
        MCore::LockGuard lock(m_setLock);
        return RemoveMotionSetWithoutLock(FindMotionSetIndexByName(motionName, isTool), delFromMemory);
    }