bool Net::equal_to(const IDevPtr& dev) const
{
    if (boost::dynamic_pointer_cast<Net, IDev>(dev) == NULL)
    {
        // not net dev
        return false;
    }

    if (hasParam(NAME) == false ||
        dev->hasParam(NAME) == false)
    {
        // don't have the name param
        return false;
    }

    if (getStringParam(NAME) == dev->getStringParam(NAME))
    {
        // name does not match
        return true;
    }
    return false;
}