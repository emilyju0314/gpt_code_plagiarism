bool Model::AddPolicies(const std::string& sec, const std::string& p_type, const std::vector<std::vector<std::string>>& rules) {
    for (const std::vector<std::string>& rule : rules)
        if (this->HasPolicy(sec, p_type, rule))
            return false;

    for (const std::vector<std::string>& rule : rules)
        this->m[sec].assertion_map[p_type]->policy.push_back(rule);

    return true;
}