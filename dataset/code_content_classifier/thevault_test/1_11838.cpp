SettingsRegistryScriptProxy::SettingsRegistryScriptProxy(AZ::SettingsRegistryInterface* const settingsRegistry)
        : m_settingsRegistry(settingsRegistry, [](AZ::SettingsRegistryInterface*) {})
        , m_notifyEventProxy(AZStd::make_shared<NotifyEventProxy>())
    {
        RegisterScriptProxyForNotify(m_settingsRegistry.get(), m_notifyEventProxy.get());
    }