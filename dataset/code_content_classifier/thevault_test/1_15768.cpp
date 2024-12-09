void WritableCatalog::InsertNestedCatalog(const string &mountpoint,
                                          Catalog *attached_reference,
                                          const hash::Any content_hash)
{
  const string sha1_string = (!content_hash.IsNull()) ?
                             content_hash.ToString() : "";

  Sql stmt(database(),
    "INSERT INTO nested_catalogs (path, sha1) VALUES (:p, :sha1);");
  bool retval =
    stmt.BindText(1, mountpoint) &&
    stmt.BindText(2, sha1_string) &&
    stmt.Execute();
  assert(retval);

  // If a reference of the in-memory object of the newly referenced
  // catalog was passed, we add this to our own children
  if (attached_reference != NULL)
    AddChild(attached_reference);

  delta_counters_.d_self_nested++;
}