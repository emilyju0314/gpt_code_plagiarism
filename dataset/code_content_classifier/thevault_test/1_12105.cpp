void LogManager::SetLogLevels(LogCallback::ELogLevel logLevels)
    {
        // iterate through all log callbacks and set it to the given log levels
        for (auto* logCallback : m_logCallbacks)
        {
            logCallback->SetLogLevels(logLevels);
        }

        // force set the log manager's log levels to the given one as well
        m_logLevels = logLevels;
    }