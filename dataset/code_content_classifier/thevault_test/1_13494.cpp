void ScanThread::startScan(const std::string& uuid, const std::string& data)

{
    BOOST_ASSERT(uuid.empty() == false);
    BOOST_ASSERT(data.empty() == false);


    // check the dev
    IResources* resources = m_factory->getResources();
    BOOST_ASSERT(resources);
    Locker lock(&m_lock);
    BOOST_ASSERT(m_dev == NULL);
    m_dev = resources->getResourceByUUID(uuid);
    if (m_dev == NULL)
    {
        throw Exception(__FILE__, __LINE__,
                        "Dev with UUID '" + uuid +
                        "' is unavailable");
    }

    // parse scan data
    setData(data);

    // start scan procedure
    m_trigger.stopWait();
}