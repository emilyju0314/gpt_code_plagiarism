void DiagnosticsLoggingFileLoggerWithoutFilter()
{
    // Define the name of a log file on your local disk
    std::string logFile = "speech-sdk-log.txt";

    // Start logging to the given file. By default it will create
    // a new file, but you have the option of appending to an existing one
    FileLogger::Start(logFile);

    // Do your Speech SDK calls... for example:
    auto config = SpeechConfig::FromSubscription("YourSubscriptionKey", "YourServiceRegion");
    auto recognizer = SpeechRecognizer::FromConfig(config);

    // Stop logging
    FileLogger::Stop();

    // Now look at the log file that was created.. 
}