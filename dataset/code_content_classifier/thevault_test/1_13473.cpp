void Network::postMainLoop() throw()
{
    try
    {
        const RouteInfoList list = getRouteInfo();
        for (RouteInfoList::const_iterator item = list.begin();
             item != list.end(); item++)
        {
            (*item)->clearInUse();
        }
    }
    catch(...)
    {
        klk_log(KLKLOG_ERROR, "Error while clearing network usage info at DB");
    }

    ModuleWithInfo<RouteInfo>::postMainLoop();
}