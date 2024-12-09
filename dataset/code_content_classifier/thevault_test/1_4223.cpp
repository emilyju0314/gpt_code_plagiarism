void DiagnosticsLoggingEventLoggerWithFilter()
{
    std::mutex mtx;
    std::vector<std::string> messages;

    // Register a callback that will get invoked by Speech SDK on every new log message
    EventLogger::SetCallback([&messages, &mtx](std::string message) {
            // Copy the string and store it for further processing. Do not do any processing in the event thread!
            std::unique_lock<std::mutex> lock(mtx);
            messages.push_back(message);
        });

    // Set an event filter, such that the callback will be invoked only for traces
    // that contain either one of the filter strings provided.
    std::initializer_list<std::string> filters = { "YourFirstString", "YourSecondString" };
    EventLogger::SetFilters(filters);

    // Do your Speech SDK calls... for example:
    auto config = SpeechConfig::FromSubscription("YourSubscriptionKey", "YourServiceRegion");
    auto recognizer = SpeechRecognizer::FromConfig(config);

    // Stop logging and clear filters by setting an empty callback
    EventLogger::SetCallback();

    // Clear filters
    EventLogger::SetFilters();

    // See resulting logs on the console
    std::cout << "Here are the logs we captured:\n";
    for (std::string message : messages)
    {
        std::cout << message;
    }
}