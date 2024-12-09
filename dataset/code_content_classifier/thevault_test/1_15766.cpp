void WritableCatalog::SetPreviousRevision(const hash::Any &hash) {
  const string sql = "INSERT OR REPLACE INTO properties "
    "(key, value) VALUES ('previous_revision', '" + hash.ToString() + "');";
  bool retval = Sql(database(), sql).Execute();
  assert(retval);
}