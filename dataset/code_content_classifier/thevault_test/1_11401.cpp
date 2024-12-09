CApprise::CApprise(const std::string &watchFolder, int watchDepth,
                       std::shared_ptr<IFileEventNotifier> fileEventNotifier) : m_watchFolder{watchFolder}, m_watchDepth{watchDepth}
    {
        // ASSERT if passed parameters invalid
        assert(watchDepth >= -1); // < -1
        try
        {
            // If no handler passed then use default
            if (fileEventNotifier.get())
            {
                m_fileEventNotifier = fileEventNotifier;
            }
            else
            {
                m_fileEventNotifier = std::make_shared<CFileEventNotifier>();
            }
            if (!watchFolder.empty())
            {
                // Remove path trailing '/'
                if ((m_watchFolder).back() == '/')
                {
                    (m_watchFolder).pop_back();
                }
                // Save away max watch depth and modify with watch folder depth value if not all (-1).
                m_watchDepth = watchDepth;
                if (watchDepth != -1)
                {
                    m_watchDepth += std::count(watchFolder.begin(), watchFolder.end(), '/');
                }
            }
            // Set watch depth for notifier
            m_fileEventNotifier->setWatchDepth(watchDepth);
            // Add non empty watch folder
            if (!m_watchFolder.empty())
            {
                m_fileEventNotifier->addWatch(m_watchFolder);
            }
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }