void CFileEventNotifier::destroyWatchTable(void)
    {
        for (auto it = m_watchMap.begin(); it != m_watchMap.end(); ++it)
        {
            if (inotify_rm_watch(m_inotifyFd, it->first) == -1)
            {
                throw std::system_error(std::error_code(errno, std::system_category()), "inotify_rm_watch() error");
            }
        }
        if (close(m_inotifyFd) == -1)
        {
            throw std::system_error(std::error_code(errno, std::system_category()), "inotify close() error");
        }
    }