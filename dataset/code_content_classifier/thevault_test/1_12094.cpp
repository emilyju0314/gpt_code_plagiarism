EMStudioPlugin* PluginManager::CreateWindowOfType(const char* pluginType, const char* objectName)
    {
        // try to locate the plugin type
        const size_t pluginIndex = FindPluginByTypeString(pluginType);
        if (pluginIndex == InvalidIndex)
        {
            return nullptr;
        }

        // create the new plugin of this type
        EMStudioPlugin* newPlugin = m_plugins[ pluginIndex ]->Clone();

        // init the plugin
        newPlugin->CreateBaseInterface(objectName);

        // register as active plugin. This has to be done at this point since
        // the initialization could try to access the plugin and assume that
        // is active.
        m_activePlugins.push_back(newPlugin);

        newPlugin->Init();

        return newPlugin;
    }