bool Enforcer :: RemoveFilteredNamedGroupingPolicy(const std::string& p_type, int field_index, const std::vector<std::string>& field_values) {
    bool rule_removed = this->removeFilteredPolicy("g", p_type, field_index, field_values);

    if(m_auto_build_role_links)
        this->BuildRoleLinks();

    return rule_removed;
}