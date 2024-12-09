void DiagnosticsLoggingFileLoggerWithFilter()
{
    // Define the name of a log file on your local disk
    std::string logFile = "speech-sdk-log.txt";

    // Start logging to the given file, but Log only traces
    // that contain either one of the filter strings provided.
    // By default it will create a new file, but you have the option of
    // appending to an existing one.
    std::initializer_list<std::string> filters = { "YourFirstString", "YourSecondString" };
    FileLogger::SetFilters(filters);
    FileLogger::Start(logFile);

    // Do your Speech SDK calls... for example:
    auto config = SpeechConfig::FromSubscription("YourSubscriptionKey", "YourServiceRegion");
    auto recognizer = SpeechRecognizer::FromConfig(config);

    // Stop logging and clear filters
    FileLogger::Stop();

    // Clear filters
    FileLogger::SetFilters();

    // Now look at the log file that was created.. 
}