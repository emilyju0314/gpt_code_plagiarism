void WritableCatalogManager::TouchDirectory(const DirectoryEntryBase &entry,
                                            const std::string &directory_path)
{
  assert(entry.IsDirectory());

  const string entry_path = MakeRelativePath(directory_path);
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

  // since we deal with a directory here, we might just touch a
  // nested catalog transition point. If this is the case we would need to
  // update two catalog entries:
  //   * the nested catalog MOUNTPOINT in the parent catalog
  //   * the nested catalog ROOT in the nested catalog

  // first check if we really have a nested catalog transition point
  catalog::DirectoryEntry potential_transition_point;
  PathString transition_path(entry_path.data(), entry_path.length());
  bool retval = catalog->LookupPath(transition_path,
                                    &potential_transition_point);
  assert(retval);
  if (potential_transition_point.IsNestedCatalogMountpoint()) {
    LogCvmfs(kLogCatalog, kLogVerboseMsg,
             "updating transition point at %s", entry_path.c_str());

    // find and mount nested catalog assciated to this transition point
    hash::Any nested_hash;
    retval = catalog->FindNested(transition_path, &nested_hash);
    assert(retval);
    Catalog *nested_catalog;
    nested_catalog = MountCatalog(transition_path, nested_hash, catalog);
    assert(nested_catalog != NULL);

    // update nested catalog root in the child catalog
    reinterpret_cast<WritableCatalog *>(nested_catalog)->
      TouchEntry(entry, entry_path);
  }

  SyncUnlock();
}