void TCPSocket::checkReady4Send()
{
    // check that data can be sent
    fd_set wset;
    FD_ZERO(&wset);
    FD_SET(m_sock.getDescriptor(),  &wset);

    struct timeval tv;
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    int status = select(m_sock.getDescriptor() + 1, NULL, &wset, NULL, &tv);

    if (status == -1)
    {
        // Network error
        throw Exception(__FILE__, __LINE__,
                        "Error %d in select(): %s. "
                        "Socket error. Network error",
                        errno, strerror(errno));
    }
    else if (status == 0)
    {
        throw Exception(__FILE__, __LINE__,
                        "Timeout exceed. Data can not be sent now");
    }

    /* Check possibility for output device receive data*/
    if(!FD_ISSET(m_sock.getDescriptor(), &wset))
    {
        throw Exception(__FILE__, __LINE__,
                        "Data can not be sent now");
    }
}