Aws::Utils::Logging::LogLevel AWSLogSystemInterface::GetLogLevel() const
    {
        Aws::Utils::Logging::LogLevel newLevel = m_logLevel;
        if (auto console = AZ::Interface<AZ::IConsole>::Get(); console != nullptr)
        {
            int awsLogLevel = -1;
            console->GetCvarValue("bg_awsLogLevel", awsLogLevel);
            if (awsLogLevel >= 0)
            {
                newLevel = static_cast<Aws::Utils::Logging::LogLevel>(awsLogLevel);
            }
        }
        return newLevel;
    }