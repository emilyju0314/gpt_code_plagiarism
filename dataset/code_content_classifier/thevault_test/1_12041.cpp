bool MotionManager::RemoveMotion(Motion* motion, bool delFromMemory)
    {
        MCore::LockGuard lock(m_lock);
        return RemoveMotionWithoutLock(FindMotionIndex(motion), delFromMemory);
    }