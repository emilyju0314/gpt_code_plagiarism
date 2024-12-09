Catalog* WritableCatalogManager::CreateCatalog(const PathString &mountpoint,
                                               Catalog *parent_catalog)
{
  return new WritableCatalog(mountpoint.ToString(), parent_catalog);
}