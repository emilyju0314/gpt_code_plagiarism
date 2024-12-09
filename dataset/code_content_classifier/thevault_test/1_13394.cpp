void RouteAddCommand::checkName(const std::string& name)
{
    BOOST_ASSERT(name.empty() == false);
    RouteInfoList list = getModule<Network>()->getRouteInfo();

    RouteInfoList::iterator
        test = std::find_if(list.begin(), list.end(),
                            boost::bind(mod::FindInfoByName(), _1, name));
    if (test != list.end())
    {
        throw Exception(
            __FILE__, __LINE__,
            "Route '%s' has been already assigned on "
            "'%s:%s at %s'",
            name.c_str(),
            (*test)->getHost().c_str(),
            (*test)->getPort().c_str(),
            (*test)->getDev()->getStringParam(dev::NAME).c_str());
    }
}