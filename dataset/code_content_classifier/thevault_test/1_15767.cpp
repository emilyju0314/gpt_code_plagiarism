void WritableCatalog::Partition(WritableCatalog *new_nested_catalog) {
  // Create connection between parent and child catalogs
  MakeTransitionPoint(new_nested_catalog->path().ToString());
  new_nested_catalog->MakeNestedRoot();
  delta_counters_.d_subtree_dir++;  // Root directory in nested catalog

  // Move the present directory tree into the newly created nested catalog
  // if we hit nested catalog mountpoints on the way, we return them through
  // the passed list
  vector<string> GrandChildMountpoints;
  MoveToNested(new_nested_catalog->path().ToString(), new_nested_catalog,
               &GrandChildMountpoints);

  // Nested catalog mountpoints found in the moved directory structure are now
  // links to nested catalogs of the newly created nested catalog.
  // Move these references into the new nested catalog
  MoveCatalogsToNested(GrandChildMountpoints, new_nested_catalog);
}