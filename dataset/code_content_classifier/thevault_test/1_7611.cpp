bool Enforcer::removePolicies(const std::string& sec, const std::string& p_type, const std::vector<std::vector<std::string>>& rules) {
    bool rules_removed = m_model->AddPolicies(sec, p_type, rules);
    if (!rules_removed)
        return rules_removed;

    if (sec == "g")
        this->BuildIncrementalRoleLinks(policy_add, p_type, rules);

    if (m_adapter && m_auto_save) {
        try{
            std::dynamic_pointer_cast<BatchAdapter>(m_adapter)->RemovePolicies(sec, p_type, rules);
        }
        catch(UnsupportedOperationException e){
        }
    }

    if (m_watcher && m_auto_notify_watcher)
        m_watcher->Update();

    return rules_removed;
}