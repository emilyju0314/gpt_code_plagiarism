void WritableCatalog::AddEntry(const DirectoryEntry &entry,
                               const string &entry_path,
                               const string &parent_path)
{
  SetDirty();

  hash::Md5 path_hash((hash::AsciiPtr(entry_path)));
  hash::Md5 parent_hash((hash::AsciiPtr(parent_path)));

  LogCvmfs(kLogCatalog, kLogVerboseMsg, "add entry %s", entry_path.c_str());

  bool retval =
    sql_insert_->BindPathHash(path_hash) &&
    sql_insert_->BindParentPathHash(parent_hash) &&
    sql_insert_->BindDirent(entry) &&
    sql_insert_->Execute();
  assert(retval);
  sql_insert_->Reset();

  delta_counters_.DeltaDirent(entry, 1);
}