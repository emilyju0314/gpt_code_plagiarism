void CTask::monitor(void)
    {
        try
        {
            m_taskAction->init();
            m_watcher->startWatching(false);
            // Loop until watcher stopped
            while (m_watcher->stillWatching())
            {
                IApprise::Event evt;
                m_watcher->getNextEvent(evt);
                if ((evt.id == IApprise::Event_add) && !evt.message.empty())
                {
                    m_taskAction->process(evt.message);
                    if ((m_killCount != 0) && (--(m_killCount) == 0))
                    {
                        break;
                    }
                }
            }
            // Pass any CFileApprise exceptions up chain
            if (m_watcher->getThrownException())
            {
                m_thrownException = m_watcher->getThrownException();
            }
        }
        catch (...)
        {
            // Pass any CTask thrown exceptions up chain
            m_thrownException = std::current_exception();
        }
        // Stop file watcher
        m_watcher->stopWatching();
        m_taskAction->term();
    }