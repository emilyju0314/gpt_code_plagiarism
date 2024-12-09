void Stream::checkAdapter()
{
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 600000;

    event_base_loopexit(m_adapter.klkbase, &tv);

    event_base_dispatch(m_adapter.klkbase);

    // now check the status
    fe_status_t status;

    ioctl(m_adapter.fe.fd, FE_READ_STATUS, &status);

    if (!(status & FE_HAS_SIGNAL))
    {
        throw Exception(__FILE__, __LINE__,
                        "No signal for adapter '%s'",
                        m_dev->getStringParam(dev::NAME).c_str());
    }

    if (!(status & FE_HAS_LOCK))
    {
        throw Exception(__FILE__, __LINE__,
                        "The adapter '%s' does not have lock",
                        m_dev->getStringParam(dev::NAME).c_str());
    }

}