const cli::ParameterVector
RouteAddCommand::getCompletion(const cli::ParameterVector& setparams)
{
    // [route name] [resource name]
    // [host] [port] [protocol]
    cli::ParameterVector res;
    if (setparams.empty()) // route name
    {
        // try to suggest a not used name
        RouteInfoList list = getModule<Network>()->getRouteInfo();

        // FIXME!!! seems that can not be more than 10000 routes assigned
        for (int i = 1; i < 10000; i++)
        {
            std::stringstream name;
            name << "route" << i;
            RouteInfoList::iterator
                test = std::find_if(list.begin(), list.end(),
                                    boost::bind(mod::FindInfoByName(),
                                                _1, name.str()));
            if (test == list.end())
            {
                res.push_back(name.str());
                break;
            }
        }
    }
    else if (setparams.size() == 1) // resource name
    {
        IDevList list =
            getFactory()->getResources()->getResourceByType(dev::NET);
        for (IDevList::iterator i = list.begin(); i != list.end(); i++)
        {
            res.push_back((*i)->getStringParam(dev::NAME));
        }
    }
    else if (setparams.size() == 2) // host
    {
        m_dev.reset();
        checkDev(setparams[1]);
        // set the dev name host
        BOOST_ASSERT(m_dev);
        res.push_back(m_dev->getStringParam(dev::NETADDR));
        // try to add several multicast addresses
        RouteInfoList list = getModule<Network>()->getRouteInfo();
        for (int i = 1; i < 255; i++)
        {
            std::stringstream name;
            name << "239.10.10." << i;
            RouteInfoList::iterator
                test = std::find_if(list.begin(), list.end(),
                                    boost::bind(FindInfoByHost(),
                                                _1, name.str()));
            if (test == list.end())
            {
                res.push_back(name.str());
                break;
            }
        }
    }
    else if (setparams.size() == 3) // port
    {
        const std::string host = setparams[2];
        for (int i = 20000; i < 30000; i++)
        {
            std::stringstream port;
            port << i;
            if (isPortValid(host, port.str()))
            {
                res.push_back(port.str());
                break;
            }
        }
    }
    else if (setparams.size() == 4) // protocol
    {
        const std::string host = setparams[2];
        if (!getModule<Network>()->isMulticast(host))
        {
            res.push_back(TCPIP_NAME);
        }
        res.push_back(UDP_NAME);
    }

    return res;
}