const sock::RouteInfo Protocol::getRouteInfo(const std::string& sockname)
{
    if (*(sockname.begin()) != '/')
    {
        return sock::RouteInfo("/tmp/" + sockname, 0,
                              sock::UNIXDOMAIN, sock::UNICAST);
    }

    return sock::RouteInfo(sockname, 0,
                           sock::UNIXDOMAIN, sock::UNICAST);
}