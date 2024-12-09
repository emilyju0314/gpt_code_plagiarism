bool MotionManager::RemoveMotionSet(MotionSet* motionSet, bool delFromMemory)
    {
        MCore::LockGuard lock(m_setLock);
        return RemoveMotionSetWithoutLock(FindMotionSetIndex(motionSet), delFromMemory);
    }