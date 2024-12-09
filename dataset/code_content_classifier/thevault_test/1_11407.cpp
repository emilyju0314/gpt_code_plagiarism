void CFileEventNotifier::removeWatch(const std::string &filePath)
    {
        try
        {
            std::string fileName{filePath};
            int32_t watch{0};
            // Remove path trailing '/'
            if (fileName.back() == '/')
            {
                fileName.pop_back();
            }
            // Find Watch value
            for (auto watchMapEntry : m_watchMap)
            {
                if (watchMapEntry.second.compare(filePath) == 0)
                {
                    watch = watchMapEntry.first;
                    break;
                }
            }
            if (watch)
            {
                m_watchMap.erase(watch);
                if (inotify_rm_watch(m_inotifyFd, watch) == -1)
                {
                    throw std::system_error(std::error_code(errno, std::system_category()), "inotify_rm_watch() error");
                }
            }
            else
            {
                throw std::logic_error("watch not present");
            }
        }
        catch (std::system_error &e)
        {
            // Ignore error 22 and carry on. From the documentation on this error the kernel has removed the watch for us.
            if (e.code() != std::error_code(EINVAL, std::system_category()))
            {
                throw; // Throw exception back up the chain.
            }
        }
        // No more watches so closedown
        if (m_watchMap.size() == 0)
        {
            stopEventGeneration();
        }
    }