void WritableCatalogManager::AddHardlinkGroup(DirectoryEntryBaseList &entries,
                                              const std::string &parent_directory)
{
  assert(entries.size() >= 1);
  if (entries.size() == 1) {
    DirectoryEntry fix_linkcount(entries[0]);
    fix_linkcount.set_linkcount(1);
    return AddFile(fix_linkcount, parent_directory);
  }

  LogCvmfs(kLogCatalog, kLogVerboseMsg, "adding hardlink group %s/%s",
           parent_directory.c_str(), entries[0].name().c_str());

  // Hardlink groups have to reside in the same directory.
  // Therefore we only have one parent directory here
  const string parent_path = MakeRelativePath(parent_directory);

  SyncLock();
  WritableCatalog *catalog;
  if (!FindCatalog(parent_path, &catalog)) {
    LogCvmfs(kLogCatalog, kLogStderr,
             "catalog for hardlink group containing '%s' cannot be found",
             parent_path.c_str());
    assert(false);
  }

  // Get a valid hardlink group id for the catalog the group will end up in
  // TODO: Compaction
  uint32_t new_group_id = catalog->GetMaxLinkId() + 1;
  LogCvmfs(kLogCatalog, kLogVerboseMsg, "hardlink group id %u issued",
           new_group_id);
  assert(new_group_id > 0);

  // Add the file entries to the catalog
  for (DirectoryEntryBaseList::iterator i = entries.begin(), iEnd = entries.end();
       i != iEnd; ++i)
  {
    string file_path = parent_path + "/";
    file_path.append(i->name().GetChars(), i->name().GetLength());

    // create a fully fledged DirectoryEntry to add the hardlink group to it
    // which is CVMFS specific meta data.
    DirectoryEntry hardlink(*i);
    hardlink.set_hardlink_group(new_group_id);
    hardlink.set_linkcount(entries.size());

    catalog->AddEntry(hardlink, file_path, parent_path);
  }
  SyncUnlock();
}