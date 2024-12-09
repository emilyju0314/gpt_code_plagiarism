void InThread::doLoopAction()
{
    while (getReader()->checkData() == ERROR)
    {
        if (isStopped())
            return;
        // just log and try again
        klk_log(KLKLOG_DEBUG,
                "No income connection from %s within %d sec. "
                "for input HTTP thread on %s:%d",
                getReader()->getPeerName().c_str(),
                WAITINTERVAL,
                getRoute()->getHost().c_str(),
                getRoute()->getPort());
    }
    if (isStopped())
        return;


    BinaryData buff;
    getReader()->getData(buff);
    BOOST_ASSERT(buff.empty() == false);

#if 0
    klk_log(KLKLOG_DEBUG,
            "Got %d bytes for HTTP streamer at inthread", buff.size());
#endif

    // send the data to recived connection from end-users
    getFactory()->getConnectThreadContainer()->sendConnectionData(
        m_info->getPath(), buff);
}