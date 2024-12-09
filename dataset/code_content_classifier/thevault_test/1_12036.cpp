bool MotionManager::RemoveMotionByID(uint32 id, bool delFromMemory)
    {
        MCore::LockGuard lock(m_lock);
        return RemoveMotionWithoutLock(FindMotionIndexByID(id), delFromMemory);
    }