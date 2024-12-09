std::vector<PluginEntry*> PluginRegistry::getAll()
{
  std::vector<PluginEntry*> result;
  for (auto element : m_entries) {
    std::map<std::string, PluginEntry*> map = element.second;
    for (auto entry : map) {
      result.push_back(entry.second);
    }
  }
  return result;
}