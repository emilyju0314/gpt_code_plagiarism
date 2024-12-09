bool Enforcer::addPolicy(const std::string& sec, const std::string& p_type, const std::vector<std::string>& rule) {
    bool rule_added = m_model->AddPolicy(sec, p_type, rule);
    if(!rule_added)
        return rule_added;

    if (sec == "g") {
        std::vector<std::vector<std::string>> rules{rule};
        this->BuildIncrementalRoleLinks(policy_add, p_type, rules);
    }

    if (m_adapter && m_auto_save) {
        try {
            m_adapter->AddPolicy(sec, p_type, rule);
        }
        catch(UnsupportedOperationException e) {
        }
    }

    if (m_watcher && m_auto_notify_watcher) {
        if (IsInstanceOf<WatcherEx>(m_watcher.get())) {
            std::dynamic_pointer_cast<WatcherEx>(m_watcher)->UpdateForAddPolicy(rule);
        }
        else
            m_watcher->Update();
    }

    return rule_added;
}