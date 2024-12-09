void DiagnosticsLoggingMemoryLogger()
{
    // Optional - Apply a filter, such that only traces that contain either one of the
    // filter strings will be logged
    /*
    std::initializer_list<std::string> filters = { "YourFirstString", "YourSecondString" };
    MemoryLogger::SetFilters(filters);
    */

    // Turn on logging to memory
    MemoryLogger::Start();

    // Do your Speech SDK calls... for example:
    auto config = SpeechConfig::FromSubscription("YourSubscriptionKey", "YourServiceRegion");
    auto recognizer = SpeechRecognizer::FromConfig(config);

    // Define the full path and name of a log file on your local disk
    std::string logFile = "speech-sdk-log.txt";

    // At any time (while still logging or after logging is stopped) you can dump the traces
    // in memory to a file:
    MemoryLogger::Dump(logFile);

    // Or to any stream object that is derived from std::ostream. For example, std::cout.
    // Using std::cout will enable logging to the standard output stream (your console Windows):
    MemoryLogger::Dump(std::cout);

    // Or to a vector of strings, and see the results on the console:
    std::vector<std::string> messages = MemoryLogger::Dump();

    std::cout << "Here are the logs we captured:\n";
    for (std::string message : messages)
    {
        std::cout << message;
    }

    // Stop logging to memory
    MemoryLogger::Stop();

    // Clear filters if previously set
    MemoryLogger::SetFilters();
}