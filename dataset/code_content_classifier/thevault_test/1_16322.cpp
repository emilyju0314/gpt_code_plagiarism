bool WritableCatalogManager::FindCatalog(const string     &path,
                                         WritableCatalog **result,
                                         DirectoryEntry   *dirent) {
  const PathString ps_path(path);

  Catalog *best_fit =
    AbstractCatalogManager<Catalog>::FindCatalog(ps_path);
  assert(best_fit != NULL);
  Catalog *catalog = NULL;
  bool retval = MountSubtree(ps_path, best_fit, &catalog);
  if (!retval)
    return false;

  catalog::DirectoryEntry dummy;
  if (NULL == dirent) {
    dirent = &dummy;
  }
  bool found = catalog->LookupPath(ps_path, dirent);
  if (!found || !catalog->IsWritable())
    return false;

  *result = static_cast<WritableCatalog *>(catalog);
  return true;
}