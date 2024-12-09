void DiagnosticsLoggingEventLoggerWithoutFilter()
{
    std::mutex mtx;
    std::vector<std::string> messages;

    // Register a callback that will get invoked by Speech SDK on every new log message
    EventLogger::SetCallback([&messages, &mtx](std::string message) {
            // Copy the string and store it for further processing. Do not do any processing in the event thread!
            std::unique_lock<std::mutex> lock(mtx);
            messages.push_back(message);
        });

    // Do your Speech SDK calls... for example:
    auto config = SpeechConfig::FromSubscription("YourSubscriptionKey", "YourServiceRegion");
    auto recognizer = SpeechRecognizer::FromConfig(config);

    // Stop logging by setting an empty callback
    EventLogger::SetCallback();

    // See resulting logs on the console
    std::cout << "Here are the logs we captured:\n";
    for (std::string message : messages)
    {
        std::cout << message;
    }
}