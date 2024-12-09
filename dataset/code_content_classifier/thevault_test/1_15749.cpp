void WritableCatalogManager::RemoveNestedCatalog(const string &mountpoint) {
  const string nested_root_path = MakeRelativePath(mountpoint);

  SyncLock();
  // Find the catalog which should be removed
  WritableCatalog *nested_catalog = NULL;
  if (!FindCatalog(nested_root_path, &nested_catalog)) {
    LogCvmfs(kLogCatalog, kLogStderr, "failed to remove nested catalog '%s': "
             "mountpoint was not found in current catalog structure",
             nested_root_path.c_str());
    assert(false);
  }

  // Check if the found catalog is really the nested catalog to be deleted
  assert(!nested_catalog->IsRoot() &&
         (nested_catalog->path().ToString() == nested_root_path));

  // Merge all data from the nested catalog into it's parent
  nested_catalog->MergeIntoParent();

  // Delete the catalog database file from the working copy
  if (unlink(nested_catalog->database_path().c_str()) != 0) {
    LogCvmfs(kLogCatalog, kLogStderr,
             "unable to delete the removed nested catalog database file '%s'",
             nested_catalog->database_path().c_str());
    assert(false);
  }

  // Remove the catalog from internal data structures
  DetachCatalog(nested_catalog);
  SyncUnlock();
}