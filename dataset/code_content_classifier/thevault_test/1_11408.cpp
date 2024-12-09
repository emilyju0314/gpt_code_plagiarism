void CFileEventNotifier::getNextEvent(IApprise::Event &evt)
    {
        std::unique_lock<std::mutex> locker(m_queuedEventsMutex);
        // Wait for something to happen. Either an event or stop running
        m_queuedEventsWaiting.wait(locker, [&]() {
            return (!m_queuedEvents.empty() || !m_doWork.load());
        });
        // return next event from queue
        if (!m_queuedEvents.empty())
        {
            evt = m_queuedEvents.front();
            m_queuedEvents.pop();
        }
        else
        {
            evt.id = IApprise::Event_none;
            evt.message = "";
        }
    }