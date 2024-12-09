std::string DevProxy::getStringParam(const std::string& uuid,
                                     const std::string& key, const Ice::Current&)
{
    return getDev(uuid)->getStringParam(key);
}