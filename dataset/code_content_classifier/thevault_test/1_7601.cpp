bool Model::AddPolicy(const std::string& sec, const std::string& p_type, const std::vector<std::string>& rule) {
    if(!this->HasPolicy(sec, p_type, rule)) {
        m[sec].assertion_map[p_type]->policy.push_back(rule);
        return true;
    }

    return false;
}