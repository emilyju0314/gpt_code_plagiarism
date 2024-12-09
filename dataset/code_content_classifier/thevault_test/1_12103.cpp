void LogManager::RemoveAllByType(uint32 type)
    {
        LockGuard lock(m_mutex);

        // Put all the callbacks of the type to be removed at the end of the vector
        m_logCallbacks.erase(AZStd::remove_if(begin(m_logCallbacks), end(m_logCallbacks), [type](const LogCallback* callback)
        {
            if (callback->GetType() == type)
            {
                delete callback;
                return true;
            }
            return false;
        }));

        // collect the enabled log levels
        InitLogLevels();
    }