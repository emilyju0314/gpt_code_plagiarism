bool Enforcer :: HasNamedGroupingPolicy(const std::string& p_type, const std::vector<std::string>& params) {
    if (params.size() == 1) {
        std::vector<std::string> str_slice{params[0]};
        return m_model->HasPolicy("g", p_type, str_slice);
    }

    std::vector<std::string> policy;
    for (int i = 0 ; i < params.size() ; i++)
        policy.push_back(params[i]);
    return m_model->HasPolicy("g", p_type, policy);
}