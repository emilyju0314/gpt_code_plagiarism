void Base::setParam(const std::string& key,
                    const int value,
                    bool mutable_flag)
{
    set<int>(key, value, mutable_flag);
}