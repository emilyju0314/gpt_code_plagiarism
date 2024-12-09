CFileEventNotifier::CFileEventNotifier() : m_doWork{true}
    {
        // Allocate inotify read buffer
        m_inotifyBuffer = std::make_unique<std::uint8_t[]>(kInotifyEventBuffLen);
        // Create watch table
        initialiseWatchTable();
    }