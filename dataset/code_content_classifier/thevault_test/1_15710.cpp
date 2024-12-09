bool detach_intermediate(const unsigned cat_id) {
    LogCvmfs(kLogCatalog, kLogDebug,  "detach intermediate catalog %d", cat_id);

    if (stmts_unlink[cat_id]) {
      sqlite3_finalize(stmts_unlink[cat_id]);
      stmts_unlink[cat_id] = NULL;
    }
    if (stmts_update_inode[cat_id]) {
      sqlite3_finalize(stmts_update_inode[cat_id]);
      stmts_update_inode[cat_id] = NULL;
    }
    if (stmts_update[cat_id]) {
      sqlite3_finalize(stmts_update[cat_id]);
      stmts_update[cat_id] = NULL;
    }
    if (stmts_insert[cat_id]) {
      sqlite3_finalize(stmts_insert[cat_id]);
      stmts_insert[cat_id] = NULL;
    }
    if (stmts_ls[cat_id]) {
      sqlite3_finalize(stmts_ls[cat_id]);
      stmts_ls[cat_id] = NULL;
    }
    if (stmts_lookup_nested[cat_id]) {
      sqlite3_finalize(stmts_lookup_nested[cat_id]);
      stmts_lookup_nested[cat_id] = NULL;
    }
    if (stmts_parent[cat_id]) {
      sqlite3_finalize(stmts_parent[cat_id]);
      stmts_parent[cat_id] = NULL;
    }
    if (stmts_lookup[cat_id]) {
      sqlite3_finalize(stmts_lookup[cat_id]);
      stmts_lookup[cat_id] = NULL;
    }
    if (stmts_lookup_inode[cat_id]) {
      sqlite3_finalize(stmts_lookup_inode[cat_id]);
      stmts_lookup_inode[cat_id] = NULL;
    }
    in_transaction[cat_id] = false;

    LogCvmfs(kLogCatalog, kLogDebug,
             "detach intermediate %d, statements removed, closing db", cat_id);
    const int result = sqlite3_close(db[cat_id]);
    if (result == SQLITE_OK) {
      db[cat_id] = NULL;
      return true;
    } else return false;
  }