static bool create_db(const unsigned cat_id, const bool read_only) {
    const string sql_catalog = "CREATE TABLE IF NOT EXISTS catalog "
    "(md5path_1 INTEGER, md5path_2 INTEGER, parent_1 INTEGER, parent_2 INTEGER, inode INTEGER, "
    "hash BLOB, size INTEGER, mode INTEGER, mtime INTEGER, flags INTEGER, name TEXT, symlink TEXT, "
    "CONSTRAINT pk_catalog PRIMARY KEY (md5path_1, md5path_2));";
    if (!sql_exec(db[cat_id], sql_catalog))
      return false;

    const string sql_index = "CREATE INDEX IF NOT EXISTS idx_catalog_parent "
    "ON catalog (parent_1, parent_2);";
    if (!sql_exec(db[cat_id], sql_index))
      return false;

    const string sql_index_ino = "CREATE INDEX IF NOT EXISTS idx_catalog_inode "
    "ON catalog (inode);";
    if (!sql_exec(db[cat_id], sql_index_ino))
      return false;

    const string sql_props = "CREATE TABLE IF NOT EXISTS properties "
    "(key TEXT, value TEXT, CONSTRAINT pk_properties PRIMARY KEY (key));";
    if (!sql_exec(db[cat_id], sql_props))
      return false;

    const string sql_nested = "CREATE TABLE IF NOT EXISTS nested_catalogs "
    "(path TEXT, sha1 TEXT, CONSTRAINT pk_nested_catalogs PRIMARY KEY (path));";
    if (!sql_exec(db[cat_id], sql_nested))
      return false;

    if (!read_only) {
      const string sql_revision = "INSERT OR IGNORE INTO properties (key, value) VALUES ('revision', 0);";
      if (!sql_exec(db[cat_id], sql_revision))
        return false;
      const string sql_schema = "INSERT OR REPLACE INTO properties (key, value) VALUES ('schema', '1.2');";
      if (!sql_exec(db[cat_id], sql_schema))
        return false;
		} else {
      /* Check Schema */
      bool result = true;

      const string sql = "SELECT value FROM properties WHERE key='schema';";
      sqlite3_stmt *stmt;
      sqlite3_prepare_v2(db[cat_id], sql.c_str(), -1, &stmt, NULL);
      int err = sqlite3_step(stmt);
      if (err == SQLITE_ROW) {
        const string schema = string((char *)sqlite3_column_text(stmt, 0));
        if (schema.find("1.", 0) != 0)
          result = false;
      } else {
        //logmsg("No schema version in catalog");
        result = false;
      }
      sqlite3_finalize(stmt);

      return result;
    }

    return true;
  }