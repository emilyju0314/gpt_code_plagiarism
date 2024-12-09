void CCurl::setErrorBuffer(size_t errorBufferSize)
    {
        this->m_errorBuffer.resize(errorBufferSize);
        auto code = curl_easy_setopt(m_curlConnection, CURLOPT_ERRORBUFFER, m_errorBuffer.c_str());
        if (code != CURLE_OK)
        {
            throw Exception("Failed to set error buffer [" + std::to_string(code) + "]");
        }
    }