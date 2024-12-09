void MotionQueue::RemoveEntry(size_t nr)
    {
        if (m_motionSystem->RemoveMotionInstance(m_entries[nr].m_motion) == false)
        {
            GetMotionInstancePool().Free(m_entries[nr].m_motion);
        }

        m_entries.erase(AZStd::next(begin(m_entries), nr));
    }