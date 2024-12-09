void InUDPThread::doLoop()
{
    initReader();

    while (!isStopped())
    {
        // do something only if we have a connectons for this input
        if (m_sem.isLocked())
        {
            // just log
            klk_log(KLKLOG_DEBUG,
                    "No any output connection "
                    "for input HTTP thread on %s:%d. "
                    "Stop receiving info",
                    getRoute()->getHost().c_str(),
                    getRoute()->getPort());
            break;
        }

        doLoopAction();
    }
}