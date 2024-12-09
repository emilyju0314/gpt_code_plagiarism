bool Model::HasPolicy(const std::string& sec, const std::string& p_type, const std::vector<std::string>& rule) {
    auto& policy = this->m[sec].assertion_map[p_type]->policy;
    for(const std::vector<std::string>& policy_it : policy)
        if (ArrayEquals(rule, policy_it))
            return true;

    return false;
}