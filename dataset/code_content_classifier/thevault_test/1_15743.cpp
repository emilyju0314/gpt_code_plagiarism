void WritableCatalogManager::AddDirectory(const DirectoryEntryBase &entry,
                                          const std::string &parent_directory)
{
  const string parent_path = MakeRelativePath(parent_directory);
  string directory_path = parent_path + "/";
  directory_path.append(entry.name().GetChars(), entry.name().GetLength());

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
             "parent directory for directory '%s' cannot be found",
             directory_path.c_str());
    assert(false);
  }

  DirectoryEntry fixed_hardlink_count(entry);
  fixed_hardlink_count.set_linkcount(2);
  catalog->AddEntry(fixed_hardlink_count, directory_path, parent_path);

  parent_entry.set_linkcount(parent_entry.linkcount() + 1);
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