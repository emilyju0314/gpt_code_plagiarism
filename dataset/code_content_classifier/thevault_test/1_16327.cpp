bool WritableCatalogManager::IsTransitionPoint(const string &mountpoint) {
  const string path = MakeRelativePath(mountpoint);

  SyncLock();
  WritableCatalog *catalog;
  DirectoryEntry entry;
  if (!FindCatalog(path, &catalog, &entry)) {
    LogCvmfs(kLogCatalog, kLogStderr,
             "catalog for directory '%s' cannot be found", path.c_str());
    assert(false);
  }
  const bool result = entry.IsNestedCatalogRoot();
  SyncUnlock();
  return result;
}