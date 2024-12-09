void LogCallback::SetLogLevels(ELogLevel logLevels)
    {
        m_logLevels = logLevels;
        GetLogManager().InitLogLevels();
    }