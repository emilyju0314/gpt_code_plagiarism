bool MotionManager::RemoveMotionSetByID(uint32 id, bool delFromMemory)
    {
        MCore::LockGuard lock(m_setLock);
        return RemoveMotionSetWithoutLock(FindMotionSetIndexByID(id), delFromMemory);
    }