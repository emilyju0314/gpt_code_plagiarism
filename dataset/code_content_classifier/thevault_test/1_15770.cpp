void WritableCatalog::UpdateNestedCatalog(const string &path,
                                          const hash::Any &hash)
{
  const string sha1_str = hash.ToString();
  const string sql = "UPDATE nested_catalogs SET sha1 = :sha1 "
    "WHERE path = :path;";
  Sql stmt(database(), sql);

  bool retval =
    stmt.BindText(1, sha1_str) &&
    stmt.BindText(2, path) &&
    stmt.Execute();

  assert(retval);
}