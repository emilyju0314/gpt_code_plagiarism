void DevProxy::setIntParam(const std::string& uuid,
                           const std::string& key, int value,
                           bool mutable_flag, const Ice::Current&)
{
    return getDev(uuid)->setParam(key, value, mutable_flag);
}