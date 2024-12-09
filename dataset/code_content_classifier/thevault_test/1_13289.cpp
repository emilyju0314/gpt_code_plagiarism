void Processor::doStartScan(const IMessagePtr& in,
                            const IMessagePtr& out)
{
    const std::string source = in->getValue(msg::key::DVBSOURCE);
    BOOST_ASSERT(source.empty() == false);

    // try to find idle dev with such type
    IDevList devs =
        m_factory->getResources()->getResourceByType(dev::DVB_ALL);
    IDevList::iterator find =
        std::find_if(devs.begin(), devs.end(),
                     boost::bind<bool>(CheckFreeDev(), _1, source));
    if (find == devs.end())
    {
        throw Exception(__FILE__, __LINE__,
                             "No free DVB dev for scan on '%s'",
                             source.c_str());
    }

    BOOST_ASSERT(out);
    out->setData(msg::key::RESOURCE, (*find)->getStringParam(dev::UUID));

    // set dev state
    (*find)->setState(dev::WORK);
    (*find)->setParam(dev::DVBACTIVITY, dev::SCANING);
}