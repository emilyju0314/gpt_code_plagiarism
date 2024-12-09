void WritableCatalogManager::AddFile(const DirectoryEntry  &entry,
                                     const std::string     &parent_directory) {
  const string parent_path = MakeRelativePath(parent_directory);
  const string file_path   = entry.GetFullPath(parent_path);

  SyncLock();
  WritableCatalog *catalog;
  if (!FindCatalog(parent_path, &catalog)) {
    LogCvmfs(kLogCatalog, kLogStderr, "catalog for file '%s' cannot be found",
             file_path.c_str());
    assert(false);
  }

  assert(!entry.IsRegular() || !entry.checksum().IsNull());
  catalog->AddEntry(entry, file_path, parent_path);
  SyncUnlock();
}