const std::string
InfoCommand::getParamInfo(const std::string& param, const IDevPtr& dev) const
{
    if (dev->hasParam(param))
    {
        return dev->getStringParam(param);
    }

    return NOTAVAILABLE;
}