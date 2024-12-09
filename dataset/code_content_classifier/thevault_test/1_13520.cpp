void Parameters::add(const std::string& key, int param)
{
    checkKey(key);
    std::stringstream data;
    data << param;
    m_params.push_back(Pair(key, data.str()));
}