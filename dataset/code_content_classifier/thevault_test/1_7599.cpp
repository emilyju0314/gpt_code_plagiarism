std::vector<std::vector<std::string>> Model::GetFilteredPolicy(const std::string& sec, const std::string& p_type, int field_index, const std::vector<std::string>& field_values) {
    std::vector<std::vector<std::string>> res;
    const std::vector<std::vector<std::string>>& policy = m[sec].assertion_map[p_type]->policy;
    res.reserve(policy.size());
    for(int i = 0 ; i < policy.size() ; i++){
        bool matched = true;
        for(int j = 0 ; j < field_values.size() ; j++){
            if(field_values[j] != "" && (policy[i])[field_index + j] != field_values[j] ){
                matched = false;
                break;
            }
        }
        if(matched)
            res.push_back(policy[i]);
    }

    return res;
}