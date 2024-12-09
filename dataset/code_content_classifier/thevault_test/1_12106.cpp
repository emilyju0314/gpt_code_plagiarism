size_t LogManager::FindLogCallback(LogCallback* callback) const
    {
        // iterate through all callbacks
        for (size_t i = 0; i < m_logCallbacks.size(); ++i)
        {
            if (m_logCallbacks[i] == callback)
            {
                return i;
            }
        }

        return InvalidIndex;
    }