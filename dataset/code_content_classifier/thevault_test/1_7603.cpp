bool Model::RemovePolicy(const std::string& sec, const std::string& p_type, const std::vector<std::string>& rule) {
    // Caching policy by reference for the scope of this function
    auto& policy = m[sec].assertion_map[p_type]->policy;
    for (auto it = policy.begin(); it != policy.end(); ++it) {
        if(ArrayEquals(rule, *it)) {
            policy.erase(it);
            return true;
        }
    }
    return false;
}