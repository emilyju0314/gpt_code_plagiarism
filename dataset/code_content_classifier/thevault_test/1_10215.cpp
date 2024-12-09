LogLevel DefaultLogger::getLevelFromString(const std::string& level) {
    if(level == "TRACE") {
        return LogLevel::TRACE;
    }
    if(level == "DEBUG") {
        return LogLevel::DEBUG;
    }
    if(level == "INFO") {
        return LogLevel::INFO;
    }
    if(level == "WARNING") {
        return LogLevel::WARNING;
    }
    if(level == "ERROR") {
        return LogLevel::ERROR;
    }
    if(level == "STATUS") {
        return LogLevel::STATUS;
    }
    if(level == "FATAL") {
        return LogLevel::FATAL;
    }

    throw std::invalid_argument("unknown log level");
}