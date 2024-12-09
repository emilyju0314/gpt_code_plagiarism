void ScanThread::stopScan() throw()
{
    Locker lock(&m_lock);
    if (m_processor)
        m_processor->stopProcessing();
}