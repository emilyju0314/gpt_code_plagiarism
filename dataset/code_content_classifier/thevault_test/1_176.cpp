void PluginRegistry::unloadPlugin(PluginEntry *pluginEntry)
{
  if (!pluginEntry) {
      return;
  }

  std::string pluginId = pluginEntry->getId();

  void *plugin = m_pluginHandleMap[pluginId];
  void *lib = m_pluginLibMap[pluginId];

  if (nullptr != lib) {
    if (nullptr != plugin) {
      PluginUtils::DestroyPlugin(lib, plugin);
      m_pluginHandleMap.erase(m_pluginHandleMap.find(pluginId));
    }

    PluginUtils::ClosePluginLibrary(lib);
    m_pluginLibMap.erase(m_pluginLibMap.find(pluginId));
    std::cout << "Plugin with id = " << pluginId << " successfully unloaded" << std::endl;
  }
}