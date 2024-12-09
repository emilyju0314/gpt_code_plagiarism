int DevProxy::getIntParam(const std::string& uuid,
                          const std::string& key, const Ice::Current&)
{
    return getDev(uuid)->getIntParam(key);
}