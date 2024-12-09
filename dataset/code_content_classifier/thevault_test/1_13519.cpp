void Parameters::add(const std::string& key, const std::string& param)
{
    checkKey(key);
    std::string queryparam = "'" + param + "'";
    m_params.push_back(Pair(key, queryparam));
}