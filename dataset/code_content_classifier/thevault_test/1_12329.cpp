void MemoryTracker::UpdateGroupStatistics()
    {
        LockGuard lock(m_mutex);
        UpdateGroupStatisticsNoLock();
    }