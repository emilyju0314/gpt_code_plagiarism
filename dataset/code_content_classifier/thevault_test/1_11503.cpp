CTask::CTask(
        const std::string &watchFolder,         // Watch folder path
        std::shared_ptr<CTask::IAction> action, // Action object
        int watchDepth,                         // Watch depth -1= all, 0=just watch folder
        int killCount                           // Kill count
        )
        : m_taskAction{action}, m_killCount{killCount}
    {
        // ASSERT if passed parameters invalid
        assert(watchFolder.length() != 0); // Length == 0
        assert(watchDepth >= -1);          // < -1
        assert(action != nullptr);         // nullptr
        assert(killCount >= 0);            // < 0
        // Create CFileApprise watcher object.
        m_watcher = std::make_unique<CApprise>(watchFolder, watchDepth);
    }