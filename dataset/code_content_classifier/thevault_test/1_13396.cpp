void RouteAddCommand::checkHost(const std::string& host)
{
    m_proto = TCPIP;
    BOOST_ASSERT(host.empty() == false);
    BOOST_ASSERT(m_dev);
    if (host == m_dev->getStringParam(dev::NETADDR))
    {
        // the host value is OK
        return;
    }

    // we assign multicast if the interface support it or
    // in the case of loopback (for tests only)
    if (getModule<Network>()->isMulticast(host) &&
        (m_dev->hasParam(dev::NETMCAST) == false) &&
        (m_dev->hasParam(dev::NETLOOP) == false))
    {
        throw Exception(__FILE__, __LINE__,
                             "Dev %s does not support multicast",
                             m_dev->getStringParam(dev::NAME).c_str());
    }

    if (getModule<Network>()->isMulticast(host))
    {
        m_proto = UDP;
    }
    else
    {
        throw Exception(__FILE__, __LINE__,
                             "Host value '%s' is invalid. "
                             "The following address are allowed for '%s': "
                             "224.0.0.0 - 239.255.255.255 or %s",
                             host.c_str(),
                             m_dev->getStringParam(dev::NAME).c_str(),
                             m_dev->getStringParam(dev::NETADDR).c_str());
    }
}