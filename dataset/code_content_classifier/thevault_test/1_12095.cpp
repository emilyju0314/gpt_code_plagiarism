size_t PluginManager::FindPluginByTypeString(const char* pluginType) const
    {
        const auto foundPlugin = AZStd::find_if(begin(m_plugins), end(m_plugins), [pluginType](const EMStudioPlugin* plugin)
        {
            return AzFramework::StringFunc::Equal(pluginType, plugin->GetName());
        });
        return foundPlugin != end(m_plugins) ? AZStd::distance(begin(m_plugins), foundPlugin) : InvalidIndex;
    }