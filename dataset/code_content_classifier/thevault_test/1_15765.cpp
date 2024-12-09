void WritableCatalog::IncrementRevision() {
  const string sql =
    "UPDATE properties SET value=value+1 WHERE key='revision';";
  bool retval = Sql(database(), sql).Execute();
  assert(retval);
}