void WritableCatalogManager::TouchFile(const DirectoryEntryBase &entry,
                                       const std::string &file_path) {
  assert (!entry.IsDirectory());

  const string entry_path = MakeRelativePath(file_path);
  const string parent_path = GetParentPath(entry_path);

  SyncLock();
  // find the catalog to be updated
  WritableCatalog *catalog;
  if (!FindCatalog(parent_path, &catalog)) {
    LogCvmfs(kLogCatalog, kLogStderr, "catalog for entry '%s' cannot be found",
             entry_path.c_str());
    assert(false);
  }

  catalog->TouchEntry(entry, entry_path);
  SyncUnlock();
}