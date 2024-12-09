EMStudioPlugin* PluginManager::FindActivePlugin(uint32 classID) const
    {
        const auto foundPlugin = AZStd::find_if(begin(m_activePlugins), end(m_activePlugins), [classID](const EMStudioPlugin* plugin)
        {
            return plugin->GetClassID() == classID;
        });
        return foundPlugin != end(m_activePlugins) ? *foundPlugin : nullptr;
    }