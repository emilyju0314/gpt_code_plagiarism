bool HistoryDatabase::CreateEmptyDatabase() {
  assert(read_write());

  return CreateTagsTable() &&
         CreateRecycleBinTable();
}