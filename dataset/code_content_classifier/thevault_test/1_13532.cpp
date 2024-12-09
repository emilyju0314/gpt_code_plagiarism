void ConnectThread::parseRequest(const std::string& reqstr)
{
    std::vector<std::string> vec = base::Utils::split(reqstr, "\t ");
    if (vec.size() != 3)
    {
        throw Exception(__FILE__, __LINE__,
                        "Incorrect HTTP request: " + reqstr);
    }

    Locker lock(&m_lock);

    // request type
    if (vec[0] == "HEAD")
    {
        m_request_type = HEAD;
    }
    else if (vec[0] == "GET")
    {
        m_request_type = GET;
    }
    else
    {
        throw Exception(__FILE__, __LINE__,
                        "Incorrect HTTP request: " + reqstr);
    }


    // path
    if (*vec[1].begin() != '/')
    {
        throw Exception(__FILE__, __LINE__,
                        "Incorrect HTTP request: " + reqstr);
    }
    m_path = vec[1];

    // HTTP version
    m_http_version = HTTP_UNKNOWN;
    if (vec[2] == "HTTP/1.0")
    {
        m_http_version = HTTP10;
    }
    else if (vec[2] == "HTTP/1.1")
    {
        m_http_version = HTTP11;
    }
    else
    {
        throw Exception(__FILE__, __LINE__,
                        "Incorrect HTTP request: " + reqstr);
    }
}