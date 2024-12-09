void CApprise::getNextEvent(CApprise::Event &evt)
    {
        try
        {
            m_fileEventNotifier->getNextEvent(evt);
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }