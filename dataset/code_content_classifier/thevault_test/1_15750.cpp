hash::Any WritableCatalogManager::SnapshotCatalog(WritableCatalog *catalog)
  const
{
  LogCvmfs(kLogCatalog, kLogVerboseMsg, "creating snapshot of catalog '%s'",
           catalog->path().c_str());

  catalog->UpdateCounters();
  if (catalog->parent()) {
    catalog->delta_counters_.PopulateToParent(
      &catalog->GetWritableParent()->delta_counters_);
  }
  catalog->delta_counters_.SetZero();

  catalog->UpdateLastModified();
  catalog->IncrementRevision();

  // Previous revision
  if (catalog->IsRoot()) {
    catalog->SetPreviousRevision(base_hash_);
  } else {
    hash::Any hash_previous;
    const bool retval =
      catalog->parent()->FindNested(catalog->path(), &hash_previous);
    assert (retval);
    catalog->SetPreviousRevision(hash_previous);
  }

  // Compress catalog
  hash::Any hash_catalog(hash::kSha1);
  if (!zlib::CompressPath2Path(catalog->database_path(),
                               catalog->database_path() + ".compressed",
                               &hash_catalog))
  {
    PrintError("could not compress catalog " + catalog->path().ToString());
    assert(false);
  }

  // Upload catalog
  spooler_->Upload(catalog->database_path() + ".compressed",
                   "data" + hash_catalog.MakePath(1, 2) + "C");

  // Update registered catalog SHA1 in nested catalog
  if (!catalog->IsRoot()) {
    LogCvmfs(kLogCatalog, kLogVerboseMsg, "updating nested catalog link");
    WritableCatalog *parent = static_cast<WritableCatalog *>(catalog->parent());
    parent->UpdateNestedCatalog(catalog->path().ToString(), hash_catalog);
  }

  return hash_catalog;
}