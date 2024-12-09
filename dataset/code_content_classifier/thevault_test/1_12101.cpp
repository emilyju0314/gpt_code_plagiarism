void LogManager::AddLogCallback(LogCallback* callback)
    {
        MCORE_ASSERT(callback);
        LockGuard lock(m_mutex);

        // add the callback to the stack
        m_logCallbacks.emplace_back(callback);

        // collect the enabled log levels
        InitLogLevels();
    }