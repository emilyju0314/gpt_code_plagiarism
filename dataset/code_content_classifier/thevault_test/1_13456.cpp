void BaseResources::addDev(const IDevPtr& dev)
{
    Locker lock(&m_lock);
    BOOST_ASSERT(dev);

    IDevList::iterator i = std::find_if(
        m_devlist.begin(), m_devlist.end(),
        boost::bind(FindDev(), _1, dev));
    if (i == m_devlist.end())
    {
        dev->update();
        m_devlist.push_back(dev);
    }
    else
    {
        // device is already in
        klk_log(KLKLOG_ERROR, "Device with name '%s' has been already added",
                dev->getStringParam(NAME).c_str());
    }
}