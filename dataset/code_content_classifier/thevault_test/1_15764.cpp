void WritableCatalog::UpdateLastModified() {
  const time_t now = time(NULL);
  const string sql = "INSERT OR REPLACE INTO properties "
     "(key, value) VALUES ('last_modified', '" + StringifyInt(now) + "');";
  bool retval = Sql(database(), sql).Execute();
  assert(retval);
}