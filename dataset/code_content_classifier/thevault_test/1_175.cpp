void *PluginRegistry::loadPlugin(PluginEntry *pluginEntry)
{
  if (nullptr == pluginEntry) {
    return nullptr;
  }

  std::string pluginId = pluginEntry->getId();

  // Check if there is already a handle for this plugin
  if (nullptr != m_pluginHandleMap[pluginId]) {
    return m_pluginHandleMap[pluginId];
  }

  // Open plugin library
  std::cout << "Loading library " << pluginEntry->getLibName() << std::endl;
  void *lib = PluginUtils::OpenPluginLibrary(pluginEntry->getLibName());
  if (!lib) {
    return nullptr;
  }

  // Create and return Operation plugin instance
  void *plugin = PluginUtils::CreatePlugin(lib);

  // Add handles to internal maps for reuse
  m_pluginHandleMap[pluginId] = plugin;
  m_pluginLibMap[pluginId] = lib;

  return plugin;
}