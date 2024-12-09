void CalculatorEngine::start()
{
  PluginRegistry::getSharedInstance().initialize();
  cout << "Calculator engine started" << endl;

  // Print out all plugin entries
  std::vector<PluginEntry*> allEntries = PluginRegistry::getSharedInstance().getAll();
  for (auto entry : allEntries) {
    cout << "found plugin { " 
         << "type: " << entry->getType() 
         << ", name: " << entry->getName() 
         << ", libName: " << entry->getLibName() 
         << " }" << std::endl;
  }
}