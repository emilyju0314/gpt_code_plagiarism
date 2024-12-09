void DevProxy::setStringParam(const std::string& uuid,
                              const std::string& key,
                              const std::string& value,
                              bool mutable_flag, const Ice::Current&)
{
    return getDev(uuid)->setParam(key, value, mutable_flag);
}