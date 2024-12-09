bool RouteAddCommand::isPortValid(const std::string& host,
                                  const std::string& port)
{
    BOOST_ASSERT(port.empty() == false);

    // check that the port is an integer
    try
    {
        boost::lexical_cast<u_int>(port);
    }
    catch(boost::bad_lexical_cast&)
    {
        throw Exception(__FILE__, __LINE__,
                             "Incorrect port value: %s. Should be integer",
                             port.c_str());
    }


    // check that the port for the host is not used
    if (getModule<Network>()->isMulticast(host))
        return true; // FIXME!!!

    RouteInfoList list = getModule<Network>()->getRouteInfo();
    for (RouteInfoList::iterator item = list.begin();
         item != list.end(); item++)
    {
        if (port == (*item)->getPort() && (*item)->getHost() == host)
            return false; // already in use
    }

    return true;
}