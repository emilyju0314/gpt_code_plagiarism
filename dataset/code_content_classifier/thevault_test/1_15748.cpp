void WritableCatalogManager::CreateNestedCatalog(const std::string &mountpoint)
{
  const string nested_root_path = MakeRelativePath(mountpoint);

  SyncLock();
  // Find the catalog currently containing the directory structure, which
  // will be represented as a new nested catalog from now on
  WritableCatalog *old_catalog = NULL;
  if (!FindCatalog(nested_root_path, &old_catalog)) {
    LogCvmfs(kLogCatalog, kLogStderr, "failed to create nested catalog '%s': "
             "mountpoint was not found in current catalog structure",
             nested_root_path.c_str());
    assert(false);
  }

  // Get the DirectoryEntry for the given path, this will serve as root
  // entry for the nested catalog we are about to create
  DirectoryEntry new_root_entry;
  bool retval = old_catalog->LookupPath(PathString(nested_root_path.data(),
                                        nested_root_path.length()),
                                        &new_root_entry);
  assert(retval);

  // Create the database schema and the inital root entry
  // for the new nested catalog
  const string database_file_path = CreateTempPath(dir_temp_ + "/catalog",
                                                   0666);
  retval =
    Database::Create(database_file_path, new_root_entry, nested_root_path);
  assert(retval);

  // Attach the just created nested catalog
  Catalog *new_catalog =
    CreateCatalog(PathString(nested_root_path.data(), nested_root_path.length()),
                  old_catalog);
  retval = AttachCatalog(database_file_path, new_catalog);
  assert(retval);

  assert(new_catalog->IsWritable());
  WritableCatalog *wr_new_catalog = static_cast<WritableCatalog *>(new_catalog);

  // From now on, there are two catalogs, spanning the same directory structure
  // we have to split the overlapping directory entries from the old catalog
  // to the new catalog to re-gain a valid catalog structure
  old_catalog->Partition(wr_new_catalog);

  // Add the newly created nested catalog to the references of the containing
  // catalog
  old_catalog->InsertNestedCatalog(new_catalog->path().ToString(), NULL,
                                   hash::Any(hash::kSha1));

  // Fix subtree counters in new nested catalogs: subtree is the sum of all
  // entries of all "grand-nested" catalogs
  Catalog::NestedCatalogList *grand_nested =
    wr_new_catalog->ListNestedCatalogs();
  DeltaCounters fix_subtree_counters;
  for (Catalog::NestedCatalogList::const_iterator i = grand_nested->begin(),
       iEnd = grand_nested->end(); i != iEnd; ++i)
  {
    WritableCatalog *grand_catalog;
    retval = FindCatalog(i->path.ToString(), &grand_catalog);
    assert(retval);
    Counters grand_counters;
    retval = grand_catalog->GetCounters(&grand_counters);
    assert(retval);
    grand_counters.AddAsSubtree(&fix_subtree_counters);
  }
  DeltaCounters save_counters = wr_new_catalog->delta_counters_;
  wr_new_catalog->delta_counters_ = fix_subtree_counters;
  wr_new_catalog->UpdateCounters();
  wr_new_catalog->delta_counters_ = save_counters;

  SyncUnlock();
}