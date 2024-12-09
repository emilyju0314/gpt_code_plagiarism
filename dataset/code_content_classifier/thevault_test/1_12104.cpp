void LogManager::ClearLogCallbacks()
    {
        LockGuard lock(m_mutex);

        // get rid of the callbacks
        for (auto* logCallback : m_logCallbacks)
        {
            delete logCallback;
        }

        m_logCallbacks.clear();

        // collect the enabled log levels
        InitLogLevels();
    }