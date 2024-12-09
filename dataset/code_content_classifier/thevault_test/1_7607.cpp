std::vector<std::string> Model::GetValuesForFieldInPolicyAllTypes(const std::string& sec, int field_index) {
    std::vector<std::string> values;

    for (auto [assertion, _] : m[sec].assertion_map) {
        const std::vector<std::string>& values_for_field = this->GetValuesForFieldInPolicy(sec, assertion, field_index);
        for(const std::string& value_for_field : values_for_field)
            values.push_back(value_for_field);
    }

    ArrayRemoveDuplicates(values);

    return values;
}