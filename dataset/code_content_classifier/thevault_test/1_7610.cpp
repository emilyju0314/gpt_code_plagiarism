bool Enforcer::removePolicy(const std::string& sec, const std::string& p_type, const std::vector<std::string>& rule) {
    bool rule_removed = m_model->RemovePolicy(sec, p_type, rule);
    if(!rule_removed)
        return rule_removed;

    if (sec == "g") {
        std::vector<std::vector<std::string>> rules{rule};
        this->BuildIncrementalRoleLinks(policy_add, p_type, rules);
    }
    
    if (m_adapter && m_auto_save) {
        try {
            m_adapter->RemovePolicy(sec, p_type, rule);
        }
        catch (UnsupportedOperationException e) {
        }
    }

    if(m_watcher && m_auto_notify_watcher){
        if (IsInstanceOf<WatcherEx>(m_watcher.get())) {
            std::dynamic_pointer_cast<WatcherEx>(m_watcher)->UpdateForRemovePolicy(rule);
        }
        else
            m_watcher->Update();
    }

    return rule_removed;
}