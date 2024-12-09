void CApprise::addWatch(const std::string &filePath)
    {
        try
        {
            m_fileEventNotifier->addWatch(filePath);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }