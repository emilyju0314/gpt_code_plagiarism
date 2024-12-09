void MotionManager::AddMotion(Motion* motion)
    {
        // wait with execution until we can set the lock
        m_lock.Lock();
        m_motions.emplace_back(motion);
        m_lock.Unlock();
    }