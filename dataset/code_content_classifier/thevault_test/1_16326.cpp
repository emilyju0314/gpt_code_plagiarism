void WritableCatalogManager::CreateNestedCatalog(const std::string &mountpoint)
{
  const string nested_root_path = MakeRelativePath(mountpoint);
  const PathString ps_nested_root_path(nested_root_path);

  SyncLock();
  // Find the catalog currently containing the directory structure, which
  // will be represented as a new nested catalog and its root-entry/mountpoint
  // along the way
  WritableCatalog *old_catalog = NULL;
  DirectoryEntry new_root_entry;
  if (!FindCatalog(nested_root_path, &old_catalog, &new_root_entry)) {
    LogCvmfs(kLogCatalog, kLogStderr, "failed to create nested catalog '%s': "
             "mountpoint was not found in current catalog structure",
             nested_root_path.c_str());
    assert(false);
  }

  // Create the database schema and the inital root entry
  // for the new nested catalog
  const string database_file_path = CreateTempPath(dir_temp() + "/catalog",
                                                   0666);
  const bool volatile_content = false;
  CatalogDatabase *new_catalog_db = CatalogDatabase::Create(database_file_path);
  assert(NULL != new_catalog_db);
  // Note we do not set the external_data bit for nested catalogs
  bool retval =
           new_catalog_db->InsertInitialValues(nested_root_path,
                                               volatile_content,
                                               "",  // At this point, only root
                                                    // catalog gets VOMS authz
                                               new_root_entry);
  assert(retval);
  // TODO(rmeusel): we need a way to attach a catalog directy from an open
  // database to remove this indirection
  delete new_catalog_db;
  new_catalog_db = NULL;

  // Attach the just created nested catalog
  Catalog *new_catalog =
    CreateCatalog(ps_nested_root_path, shash::Any(), old_catalog);
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
                                   shash::Any(spooler_->GetHashAlgorithm()), 0);

  // Fix subtree counters in new nested catalogs: subtree is the sum of all
  // entries of all "grand-nested" catalogs
  // Note: taking a copy of the nested catalog list here
  const Catalog::NestedCatalogList &grand_nested =
    wr_new_catalog->ListNestedCatalogs();
  DeltaCounters fix_subtree_counters;
  for (Catalog::NestedCatalogList::const_iterator i = grand_nested.begin(),
       iEnd = grand_nested.end(); i != iEnd; ++i)
  {
    WritableCatalog *grand_catalog;
    retval = FindCatalog(i->path.ToString(), &grand_catalog);
    assert(retval);
    const Counters &grand_counters = grand_catalog->GetCounters();
    grand_counters.AddAsSubtree(&fix_subtree_counters);
  }
  DeltaCounters save_counters = wr_new_catalog->delta_counters_;
  wr_new_catalog->delta_counters_ = fix_subtree_counters;
  wr_new_catalog->UpdateCounters();
  wr_new_catalog->delta_counters_ = save_counters;

  SyncUnlock();
}