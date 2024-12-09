bool WritableCatalogManager::FindCatalog(const string &path,
                                         WritableCatalog **result)
{
  Catalog *best_fit =
    AbstractCatalogManager::FindCatalog(PathString(path.data(), path.length()));
  assert (best_fit != NULL);
  Catalog *catalog = NULL;
  bool retval = MountSubtree(PathString(path.data(), path.length()),
                             best_fit, &catalog);
  if (!retval)
    return false;

  bool found = LookupPath(path, kLookupSole, NULL);
  if (!found || !catalog->IsWritable())
    return false;

  *result = static_cast<WritableCatalog *>(catalog);
  return true;
}