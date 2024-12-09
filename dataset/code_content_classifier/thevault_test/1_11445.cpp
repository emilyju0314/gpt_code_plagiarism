CCurl::CCurl()
    {
        if (!m_globalInitialised)
        {
            curl_global_init(CURL_GLOBAL_DEFAULT);
            m_globalInitialised = true;
        }
        m_curlConnection = curl_easy_init();
        if (m_curlConnection == NULL)
        {
            throw Exception("Failed to create CURL connection.");
        }
        m_errorBuffer.resize(CURL_ERROR_SIZE);
        m_errorBuffer[0] = '\0';
    }