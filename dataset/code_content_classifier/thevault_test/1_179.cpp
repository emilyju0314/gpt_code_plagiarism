bool CalculatorEngine::isOperationSupported(std::string name)
{
  PluginEntry *pluginEntry = PluginRegistry::getSharedInstance().get(PLUGIN_OPERATION, name);
  if (!pluginEntry) {
    return false;
  }
  return true;
}