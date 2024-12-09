bool reattach(const unsigned cat_id, const string &db_file, const string &url)
  {
    int flags = SQLITE_OPEN_NOMUTEX;
    if (opened_read_only[cat_id])
      flags |= SQLITE_OPEN_READONLY;
    else
      flags |= SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;

    LogCvmfs(kLogCatalog, kLogDebug, "Re-attaching %s as %u",
             db_file.c_str(), cat_id);
    if (sqlite3_open_v2(db_file.c_str(), &db[cat_id], flags, NULL) != SQLITE_OK) {
      sqlite3_close(db[cat_id]);
      return false;
    }
    in_transaction[cat_id] = false;
    sqlite3_extended_result_codes(db[cat_id], 1);

    if (!create_db(cat_id, opened_read_only[cat_id]) || !build_prepared_stmts(cat_id)) {
      detach_intermediate(cat_id);
      return false;
    }

    catalog_urls[cat_id] = url;
    catalog_files[cat_id] = db_file;
    inode_chunks[cat_id] = realign_inode_chunks_for_catalog(cat_id, get_max_rowid(cat_id));

    return true;
  }