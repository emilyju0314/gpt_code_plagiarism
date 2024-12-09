LoadError WritableCatalogManager::LoadCatalog(const PathString &mountpoint,
                                              const hash::Any &hash,
                                              std::string *catalog_path)
{
  hash::Any effective_hash = hash.IsNull() ? base_hash_ : hash;
  const string url = stratum0_ + "/data" + effective_hash.MakePath(1, 2) + "C";
  FILE *fcatalog = CreateTempFile(dir_temp_ + "/catalog", 0666, "w",
                                  catalog_path);
  if (!fcatalog) {
    LogCvmfs(kLogCatalog, kLogStderr,
             "failed to create temp file when loading %s", url.c_str());
    assert(false);
  }

  download::JobInfo download_catalog(&url, true, false, fcatalog,
                                     &effective_hash);

  download::Failures retval = download::Fetch(&download_catalog);
  fclose(fcatalog);

  if (retval != download::kFailOk) {
    LogCvmfs(kLogCatalog, kLogStderr,
             "failed to load %s from Stratum 0 (%d)", url.c_str(), retval);
    assert(false);
  }

  return kLoadNew;
}