bool MotionManager::RemoveMotionByName(const char* motionName, bool delFromMemory, bool isTool)
    {
        MCore::LockGuard lock(m_lock);
        return RemoveMotionWithoutLock(FindMotionIndexByName(motionName, isTool), delFromMemory);
    }