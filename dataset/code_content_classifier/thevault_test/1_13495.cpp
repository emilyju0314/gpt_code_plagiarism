void ScanThread::doScanDVBS(const ScanData& data)
{
    IDevPtr dev;
    {
        Locker lock(&m_lock);
        tuneDVBS(data);
        dev = m_dev;
    }

    bool found = false;
    for (u_int diseqc = 0; diseqc < 5; diseqc++)
    {
        dev->setParam(dev::DISEQC_SRC, diseqc);
        try
        {
            // processing
            m_processor->start(dev);
        }
        catch(...)
        {
            // ignore any error here
            // incorrect diseqc can produce an error
            // during tune
            // FIXME!!! bad code
        }
        // found something?
        found = wasFound();
        // save result
        save2DB();
        if (found)
            break;
    }

    if (!found)
    {
        throw Exception(__FILE__, __LINE__, "Failed to scan");
    }
}