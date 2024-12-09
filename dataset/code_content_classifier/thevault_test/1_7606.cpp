std::vector<std::string> Model::GetValuesForFieldInPolicy(const std::string& sec, const std::string& p_type, int field_index) {
    std::vector<std::string> values;
    std::vector<std::vector<std::string>>& policy = m[sec].assertion_map[p_type]->policy;
    values.reserve(policy.size());

    for (const std::vector<std::string>& policy_it : policy)
        values.push_back(policy_it[field_index]);

    ArrayRemoveDuplicates(values);

    return values;
}