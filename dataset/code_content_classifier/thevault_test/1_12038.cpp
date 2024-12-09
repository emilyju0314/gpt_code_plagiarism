bool MotionManager::RemoveMotionByFileName(const char* fileName, bool delFromMemory, bool isTool)
    {
        MCore::LockGuard lock(m_lock);
        return RemoveMotionWithoutLock(FindMotionIndexByFileName(fileName, isTool), delFromMemory);
    }