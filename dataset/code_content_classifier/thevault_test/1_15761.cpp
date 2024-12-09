DirectoryEntry SqlLookup::GetDirent(const Catalog *catalog) const {
  DirectoryEntry result;

  const unsigned database_flags = RetrieveInt(5);
  result.catalog_ = (Catalog*)catalog;
  //result.generation_ = catalog->GetGeneration();
  result.is_nested_catalog_root_ = (database_flags & kFlagDirNestedRoot);
  result.is_nested_catalog_mountpoint_ =
    (database_flags & kFlagDirNestedMountpoint);
  const char *name = reinterpret_cast<const char *>(RetrieveText(6));
  const char *symlink = reinterpret_cast<const char *>(RetrieveText(7));

  // must be set later by a second catalog lookup
  result.parent_inode_ = DirectoryEntry::kInvalidInode;

  // retrieve the hardlink information from the hardlinks database field
  if (catalog->schema() < 2.1-Database::kSchemaEpsilon) {
    result.linkcount_ = 1;
    result.hardlink_group_ = 0;
    result.inode_ = ((Catalog*)catalog)->GetMangledInode(RetrieveInt64(12), 0);
    result.uid_ = g_uid;
    result.gid_ = g_gid;
    result.is_chunked_file_ = false;
  } else {
    const uint64_t hardlinks = RetrieveInt64(1);
    result.linkcount_ = Hardlinks2Linkcount(hardlinks);
    result.hardlink_group_ = Hardlinks2HardlinkGroup(hardlinks);
    result.inode_ = ((Catalog*)catalog)->GetMangledInode(RetrieveInt64(12),
                                                         result.hardlink_group_);
    result.uid_ = RetrieveInt64(13);
    result.gid_ = RetrieveInt64(14);
    result.is_chunked_file_ = (database_flags & kFlagFileChunk);
  }
  result.mode_ = RetrieveInt(3);
  result.size_ = RetrieveInt64(2);
  result.mtime_ = RetrieveInt64(4);
  result.checksum_ = RetrieveSha1Blob(0);
  result.name_.Assign(name, strlen(name));
  result.symlink_.Assign(symlink, strlen(symlink));
  ExpandSymlink(&result.symlink_);

  return result;
}