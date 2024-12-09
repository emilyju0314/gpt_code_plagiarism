std::pair<bool, std::vector<std::vector<std::string>>> Model::RemoveFilteredPolicy(const std::string& sec, const std::string& p_type, int field_index, const std::vector<std::string>& field_values) {
    std::vector<std::vector<std::string>> tmp;
    std::vector<std::vector<std::string>> effects;
    std::vector<std::vector<std::string>>& policy = m[sec].assertion_map[p_type]->policy;
    tmp.reserve(policy.size());
    effects.reserve(policy.size());
    bool res = false;
    for(int i = 0 ; i < policy.size() ; i++) {
        bool matched = true;
        for (int j = 0 ; j < field_values.size() ; j++) {
            if (field_values[j] != "" && (policy[i])[field_index+j] != field_values[j]) {
                matched = false;
                break;
            }
        }
        if (matched){
            effects.push_back(policy[i]);
            res = true;
        }
        else
            tmp.push_back(policy[i]);
    }

    policy = tmp;
    std::pair<bool, std::vector<std::vector<std::string>>> result(res, effects);
    return result;
}