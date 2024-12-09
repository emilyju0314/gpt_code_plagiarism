void WritableCatalog::RemoveEntry(const string &file_path) {
  hash::Md5 path_hash = hash::Md5(hash::AsciiPtr(file_path));

  DirectoryEntry entry;
  bool retval = LookupMd5Path(path_hash, &entry);
  assert(retval);

  SetDirty();

  // if the entry used to be a chunked file... remove the chunks
  if (entry.IsChunkedFile()) {
    retval =
      sql_chunks_remove_->BindPathHash(path_hash) &&
      sql_chunks_remove_->Execute();
    assert(retval);
    sql_chunks_remove_->Reset();
  }

  // remove the entry itself
  retval =
    sql_unlink_->BindPathHash(path_hash) &&
    sql_unlink_->Execute();
  assert(retval);
  sql_unlink_->Reset();

  delta_counters_.DeltaDirent(entry, -1);
}