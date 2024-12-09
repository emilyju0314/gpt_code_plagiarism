bool Enforcer :: AddNamedGroupingPolicy(const std::string& p_type, const std::vector<std::string>& params) {
    bool rule_added;
    if (params.size() == 1) {
        std::vector<std::string> str_slice{params[0]};
        rule_added = this->addPolicy("g", p_type, str_slice);
    } else {
        std::vector<std::string> policy;
        for(int i = 0 ; i < params.size() ; i++)
            policy.push_back(params[i]);

        rule_added = this->addPolicy("g", p_type, policy);
    }

    if(m_auto_build_role_links)
        this->BuildRoleLinks();

    return rule_added;
}