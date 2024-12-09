void AddFinchBlacklistToRegistry() {
  base::win::RegKey finch_blacklist_registry_key(
      HKEY_CURRENT_USER, blacklist::kRegistryFinchListPath, KEY_SET_VALUE);

  // No point in trying to continue if the registry key isn't valid.
  if (!finch_blacklist_registry_key.Valid())
    return;

  // Delete and recreate the key to clear the registry.
  finch_blacklist_registry_key.DeleteKey(L"");
  finch_blacklist_registry_key.Create(
      HKEY_CURRENT_USER, blacklist::kRegistryFinchListPath, KEY_SET_VALUE);

  std::map<std::string, std::string> params;
  variations::GetVariationParams(kBrowserBlacklistTrialName, &params);

  for (std::map<std::string, std::string>::iterator it = params.begin();
       it != params.end();
       ++it) {
    std::wstring name = base::UTF8ToWide(it->first);
    std::wstring val = base::UTF8ToWide(it->second);

    finch_blacklist_registry_key.WriteValue(name.c_str(), val.c_str());
  }
}