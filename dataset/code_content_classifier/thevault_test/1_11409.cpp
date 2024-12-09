void CFileEventNotifier::stopEventGeneration(void)
    {
        // If still active then need to close down
        if (m_doWork.load())
        {
            std::unique_lock<std::mutex> locker(m_queuedEventsMutex);
            m_doWork = false;
            m_queuedEventsWaiting.notify_one();
            destroyWatchTable();
        }
    }