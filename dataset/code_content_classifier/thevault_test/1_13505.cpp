bool DevProxy::hasParam(const std::string& uuid, const std::string& key,
                        const Ice::Current&)
{
    return getDev(uuid)->hasParam(key);
}