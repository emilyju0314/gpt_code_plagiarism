void ScanThread::doScanDVBT(const ScanData& data)
{
    IDevPtr dev;
    {
        Locker lock(&m_lock);
        tuneDVBT(data);
        dev = m_dev;
    }

    // processing
    m_processor->start(dev);
    // save result
    save2DB();
}