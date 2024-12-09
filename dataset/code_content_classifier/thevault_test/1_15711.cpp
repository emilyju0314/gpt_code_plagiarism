bool detach(const unsigned cat_id) {
    bool result = false;
    LogCvmfs(kLogCatalog, kLogDebug, "detaching catalog %d", cat_id);

    if (detach_intermediate(cat_id)) {
      num_catalogs--;
      current_catalog = 0;
      LogCvmfs(kLogCatalog, kLogDebug,
               "reorganising catalogs %d-%d", cat_id, num_catalogs);
      for (int i = cat_id; i < num_catalogs; ++i) {
        if (!detach_intermediate(i+1) ||
            !reattach(i, catalog_files[i+1], catalog_urls[i+1]))
				{
          return false;
				}
        catalog_files[i] = catalog_files[i+1];
        catalog_urls[i] = catalog_urls[i+1];
        opened_read_only[i] = opened_read_only[i+1];
        inode_chunks[i] = inode_chunks[i+1];
        in_transaction[i] = false;
      }
      stmts_unlink.pop_back();
      stmts_update_inode.pop_back();
      stmts_update.pop_back();
      stmts_insert.pop_back();
      stmts_ls.pop_back();
      stmts_lookup_nested.pop_back();
      stmts_parent.pop_back();
      stmts_lookup.pop_back();
      stmts_lookup_inode.pop_back();
      in_transaction.pop_back();
      inode_chunks.pop_back();
      opened_read_only.pop_back();
      catalog_files.pop_back();
      catalog_urls.pop_back();
      db.pop_back();
      result = true;
    }

    return result;
  }