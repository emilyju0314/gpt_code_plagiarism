void Parameters::add(const std::string& key, const char *param)

{
    checkKey(key);
    if (param == NULL)
    {
        m_params.push_back(Pair(key, "NULL"));
    }
    else
    {
        std::string paramstr(param);
        add(key, paramstr);
    }
}