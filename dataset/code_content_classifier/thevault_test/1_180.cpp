double CalculatorEngine::runOperation(std::string name, double operandA, double operandB)
{
  // Discover the requested operation plugin by name
  PluginEntry *pluginEntry = PluginRegistry::getSharedInstance().get(PLUGIN_OPERATION, name);
  if (!pluginEntry) {
    return -1;
  }

  // Create plugin instance
  Operation *plugin = reinterpret_cast<Operation*>(PluginRegistry::getSharedInstance().loadPlugin(pluginEntry));

  // Execute the plugin
  double result = plugin->execute(operandA, operandB);
#if 0
  json input;
  input["operandA"] = operandA;
  input["operandB"] = operandB;
  json output = plugin->invokeMethod("execute", input);
  double result = output["result"].get<double>();
#endif
  // Destroy plugin instance
  PluginRegistry::getSharedInstance().unloadPlugin(pluginEntry);

  // Finally, return the operation result
  return result;
}