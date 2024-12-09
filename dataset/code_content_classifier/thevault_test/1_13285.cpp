void Base::setParam(const std::string& key,
                    const std::string& value,
                    bool mutable_flag)
{
    set<std::string>(key, value, mutable_flag);
}