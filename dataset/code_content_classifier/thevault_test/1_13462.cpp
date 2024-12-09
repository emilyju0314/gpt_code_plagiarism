void Streamer::processOutRoute()
{
    const std::string route_uuid = getOutRoute();
    BOOST_ASSERT(route_uuid.empty() == false);

    if (getHTTPFactory()->getOutThread()->checkRoute(route_uuid))
    {
        // the route has been already set
        // nothing to do
        return;
    }

    // we need to setup new route
    const RouteInfoPtr new_route = getRouteInfoByUUID(route_uuid);
    // has been something set?
    if (getHTTPFactory()->getOutThread()->checkRoute())
    {
        // stop old
        stopRoute(getHTTPFactory()->getOutThread()->getRoute());
    }
    // setup new one
    getHTTPFactory()->setOutRoute(new_route);
}