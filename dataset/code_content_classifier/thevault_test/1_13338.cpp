const StringList BaseCommand::getDevNames()
{
    StringList result;
    IDevList list =
        getFactory()->getResources()->getResourceByType(dev::DVB_ALL);
    for (IDevList::iterator i = list.begin(); i != list.end(); i++)
    {
        result.push_back((*i)->getStringParam(dev::NAME));
    }

    return result;
}