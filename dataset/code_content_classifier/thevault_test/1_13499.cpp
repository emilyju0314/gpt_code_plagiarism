bool ScanThread::wasFound() const throw()
{
    Locker lock(&m_lock);
    return !m_scan_channel.empty();
}