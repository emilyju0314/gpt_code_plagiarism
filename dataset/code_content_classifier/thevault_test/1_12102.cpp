void LogManager::RemoveLogCallback(size_t index)
    {
        MCORE_ASSERT(index < m_logCallbacks.size());
        LockGuard lock(m_mutex);

        // delete it from memory
        delete m_logCallbacks[index];

        // remove the callback from the stack
        m_logCallbacks.erase(AZStd::next(begin(m_logCallbacks), index));

        // collect the enabled log levels
        InitLogLevels();
    }