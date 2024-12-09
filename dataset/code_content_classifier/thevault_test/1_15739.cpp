manifest::Manifest *WritableCatalogManager::CreateRepository(
  const string     &dir_temp,
  upload::Spooler  *spooler)
{
  // Create a new root catalog at file_path
  string file_path = dir_temp + "/new_root_catalog";

  // A newly created catalog always needs a root entry
  // we create and configure this here
  DirectoryEntry root_entry;
  root_entry.inode_             = DirectoryEntry::kInvalidInode;
  root_entry.parent_inode_      = DirectoryEntry::kInvalidInode;
  root_entry.mode_              = 16877;
  root_entry.size_              = 4096;
  root_entry.mtime_             = time(NULL);
  root_entry.uid_               = getuid();
  root_entry.gid_               = getgid();
  root_entry.checksum_          = hash::Any(hash::kSha1);
  root_entry.linkcount_         = 2;
  string root_path = "";

  // Create the database schema and the inital root entry
  if (!Database::Create(file_path, root_entry, root_path)) {
    LogCvmfs(kLogCatalog, kLogStderr, "creation of catalog '%s' failed",
             file_path.c_str());
    return NULL;
  }

  // Compress root catalog;
  string file_path_compressed = file_path + ".compressed";
  hash::Any hash_catalog(hash::kSha1);
  bool retval = zlib::CompressPath2Path(file_path, file_path_compressed,
                                        &hash_catalog);
  if (!retval) {
    LogCvmfs(kLogCatalog, kLogStderr, "compression of catalog '%s' failed",
             file_path.c_str());
    unlink(file_path.c_str());
    return NULL;
  }
  unlink(file_path.c_str());

  // Create manifest
  const string manifest_path = dir_temp + "/manifest";
  manifest::Manifest *manifest = new manifest::Manifest(hash_catalog, "");

  // Upload catalog
  spooler->Upload(file_path_compressed,
                  "data" + hash_catalog.MakePath(1, 2) + "C");
  spooler->WaitForUpload();
  spooler->WaitForTermination();
  unlink(file_path_compressed.c_str());
  if (spooler->GetNumberOfErrors() > 0) {
    LogCvmfs(kLogCatalog, kLogStderr, "failed to commit catalog %s",
             file_path_compressed.c_str());
    delete manifest;
    return NULL;
  }

  return manifest;
}