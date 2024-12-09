void WritableCatalogManager::RemoveDirectory(const std::string &path) {
  const string directory_path = MakeRelativePath(path);
	const string parent_path = GetParentPath(directory_path);

  SyncLock();
  WritableCatalog *catalog;
  if (!FindCatalog(parent_path, &catalog)) {
    LogCvmfs(kLogCatalog, kLogStderr,
             "catalog for directory '%s' cannot be found",
             directory_path.c_str());
    assert(false);
  }

  DirectoryEntry parent_entry;
  if (!catalog->LookupPath(PathString(parent_path.data(), parent_path.length()),
                           &parent_entry))
  {
    LogCvmfs(kLogCatalog, kLogStderr,
             "parent directory of directory '%s' not found",
             directory_path.c_str());
    assert(false);
  }

  parent_entry.set_linkcount(parent_entry.linkcount() - 1);

  catalog->RemoveEntry(directory_path);
  catalog->UpdateEntry(parent_entry, parent_path);
  if (parent_entry.IsNestedCatalogRoot()) {
    LogCvmfs(kLogCatalog, kLogVerboseMsg, "updating transition point %s",
             parent_path.c_str());
    WritableCatalog *parent_catalog =
      reinterpret_cast<WritableCatalog *>(catalog->parent());
    parent_entry.set_is_nested_catalog_mountpoint(true);
    parent_entry.set_is_nested_catalog_root(false);
    parent_catalog->UpdateEntry(parent_entry, parent_path);
  }
  SyncUnlock();
}