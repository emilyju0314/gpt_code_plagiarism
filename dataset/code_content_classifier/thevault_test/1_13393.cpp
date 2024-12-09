const cli::ParameterVector
RouteListCommand::getCompletion(const cli::ParameterVector& setparams)
{
    cli::ParameterVector res;
    if (setparams.empty())
    {
        res.push_back(cli::ALL);
        RouteInfoList list = getModule<Network>()->getRouteInfo();
        for (RouteInfoList::iterator item = list.begin();
             item != list.end(); item++)
        {
            res.push_back((*item)->getName());
        }
    }

    return res;
}