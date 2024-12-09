std::exception_ptr CApprise::getThrownException(void)
    {
        try
        {
            return (m_fileEventNotifier->getThrownException());
        }
        catch (const std::exception &e)
        {
            throw Exception(e.what());
        }
    }