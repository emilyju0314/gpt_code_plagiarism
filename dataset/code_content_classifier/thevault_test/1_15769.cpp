void WritableCatalog::RemoveNestedCatalog(const string &mountpoint,
                                          Catalog **attached_reference)
{
  hash::Any dummy;
  bool retval = FindNested(PathString(mountpoint.data(), mountpoint.length()),
                           &dummy);
  assert(retval);

  Sql stmt(database(),
           "DELETE FROM nested_catalogs WHERE path = :p;");
  retval =
    stmt.BindText(1, mountpoint) &&
    stmt.Execute();
  assert(retval);

  // If the reference was successfully deleted, we also have to check whether
  // there is also an attached reference in our in-memory data.
  // In this case we remove the child and return it through **attached_reference
  Catalog *child = FindChild(PathString(mountpoint.data(),
                                        mountpoint.length()));
  if (child != NULL)
    RemoveChild(child);
  if (attached_reference != NULL)
    *attached_reference = child;

  delta_counters_.d_self_nested--;
}