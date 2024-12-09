bool Enforcer::removeFilteredPolicy(const std::string& sec, const std::string& p_type, int field_index, const std::vector<std::string>& field_values){
    std::pair<int, std::vector<std::vector<std::string>>> p = m_model->RemoveFilteredPolicy(sec, p_type, field_index, field_values);
    bool rule_removed = p.first;
    std::vector<std::vector<std::string>> effects = p.second;

    if(!rule_removed)
        return rule_removed;

    if (sec == "g")
        this->BuildIncrementalRoleLinks(policy_remove, p_type, effects);

    if (m_adapter && m_auto_save) {
        try {
            m_adapter->RemoveFilteredPolicy(sec, p_type, field_index, field_values); \
        }
        catch (UnsupportedOperationException e) {
        }
    }

    if (m_watcher && m_auto_notify_watcher) {
        if (IsInstanceOf<WatcherEx>(m_watcher.get())) {
            std::dynamic_pointer_cast<WatcherEx>(m_watcher)->UpdateForRemoveFilteredPolicy(field_index, field_values);
        }
        else
            m_watcher->Update();
    }

    return rule_removed;
}