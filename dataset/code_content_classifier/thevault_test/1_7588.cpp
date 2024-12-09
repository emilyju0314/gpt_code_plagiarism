bool Enforcer :: RemoveNamedPolicy(const std::string& p_type, const std::vector<std::string>& params) {
    if (params.size() == 1) {
        std::vector<std::string> str_slice{params[0]};
        return this->removePolicy("p", p_type, str_slice);
    }

    std::vector<std::string> policy;
    for (int i = 0 ; i < params.size() ; i++)
        policy.push_back(params[i]);
    return this->removePolicy("p", p_type, policy);
}