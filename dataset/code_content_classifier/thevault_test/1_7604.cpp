bool Model::RemovePolicies(const std::string& sec, const std::string& p_type, const std::vector<std::vector<std::string>>& rules) {
    // Caching policy by reference for the scope of this function
    auto& policy = this->m[sec].assertion_map[p_type]->policy;

    bool is_equal;
    for (const std::vector<std::string>& rule : rules) {
        is_equal = false;
        for (const std::vector<std::string>& policy_it : policy) {
            if (ArrayEquals(rule, policy_it))
                is_equal = true;
        }
        if(!is_equal)
            return false;
    }

    for (const std::vector<std::string>& rule : rules) {
        for (auto policy_it = policy.begin(); policy_it != policy.end(); ++policy_it) {
            if (ArrayEquals(rule, *policy_it))
                policy.erase(policy_it);
        }
    }

    return true;
}