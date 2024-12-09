const Network::InfoSet Network::getInfoFromDB()
{
    InfoSet result;
    IDevList devs =
        getFactory()->getResources()->getResourceByType(dev::NET);
    std::for_each(devs.begin(), devs.end(),
                  boost::bind(&Network::processDev, this, _1,
                              boost::ref(result)));
    return result;
}