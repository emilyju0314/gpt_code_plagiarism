bool Enforcer::addPolicies(const std::string& sec, const std::string& p_type, const std::vector<std::vector<std::string>>& rules) {
    bool rules_added = m_model->AddPolicies(sec, p_type, rules);
    if (!rules_added)
        return rules_added;

    if (sec == "g")
        this->BuildIncrementalRoleLinks(policy_add, p_type, rules);


    if (m_adapter && m_auto_save) {
        try {
            std::dynamic_pointer_cast<BatchAdapter>(m_adapter)->AddPolicies(sec, p_type, rules);
        }
        catch(UnsupportedOperationException e) {
        }
    }

    if (m_watcher && m_auto_notify_watcher)
        m_watcher->Update();

    return rules_added;
}