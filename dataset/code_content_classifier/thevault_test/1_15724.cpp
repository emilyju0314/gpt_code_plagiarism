bool update_nested_sha1(const unsigned cat_id, const string path,
                          const hash::t_sha1 &sha1)
  {
    enforce_mem_limit();

    const string sql = "UPDATE nested_catalogs SET sha1 = :sha1 WHERE path = :path;";
    sqlite3_stmt *stmt;
    int retval = sqlite3_prepare_v2(db[cat_id], sql.c_str(), -1, &stmt, NULL);
    if (retval != SQLITE_OK) {
      sqlError = "unable to prepare update nested catalog sha1 key statement";
      return false;
    }

    const string sha1_str = sha1.to_string();
    sqlite3_bind_text(stmt, 1, &(sha1_str[0]), sha1_str.length(), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, &(path[0]), path.length(), SQLITE_STATIC);

    retval = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    return ((retval == SQLITE_DONE) || (retval == SQLITE_OK));
  }