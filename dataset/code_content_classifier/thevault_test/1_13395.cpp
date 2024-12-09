void RouteAddCommand::checkDev(const std::string& dev)
{
    IDevList list =
        getFactory()->getResources()->getResourceByType(dev::NET);
    if (list.empty())
    {
        throw Exception(__FILE__, __LINE__,
                             "There is no any network card configured. "
                             "Please use resources detect command "
                             "to detect them and restart the server");
    }

    try
    {
        m_dev = getFactory()->getResources()->getResourceByName(dev);
    }
    catch(Exception&)
    {
        std::stringstream msg;
        msg << "Unknown network devices: " << dev <<
            ".\nPossible values: ";
        for (IDevList::iterator i = list.begin(); i != list.end(); i++)
        {
            if (i != list.begin())
            {
                msg << "; ";
            }
            msg << (*i)->getStringParam(dev::NAME);
        }
        throw Exception(__FILE__, __LINE__, msg.str());
    }
    catch(...)
    {
        BOOST_ASSERT(false);
    }
}