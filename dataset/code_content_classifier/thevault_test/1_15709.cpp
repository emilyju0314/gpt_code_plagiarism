static bool build_prepared_stmts(const unsigned cat_id) {
    int err;

    /* SELECT LS */
    sqlite3_stmt *ls;
    ostringstream sql_ls;
    sql_ls << "SELECT " << cat_id << ", hash, inode, size, mode, mtime, flags, name, symlink, rowid "
    "FROM catalog WHERE (parent_1 = :p_1) AND (parent_2 = :p_2);";

    LogCvmfs(kLogCatalog, kLogDebug, "Prepared statement catalog %u: %s",
             cat_id, sql_ls.str().c_str());
    err = sqlite3_prepare_v2(db[cat_id], sql_ls.str().c_str(), -1, &ls, NULL);
    if (err != SQLITE_OK) {
      sqlError = "unable to prepare ls statement";
      return false;
    }

    /* SELECT LOOKUP */
    sqlite3_stmt *lookup;
    ostringstream sql_lookup;
    sql_lookup << "SELECT " << cat_id << ", hash, inode, size, mode, mtime, flags, name, symlink, rowid "
    "FROM catalog "
    "WHERE (md5path_1 = :md5_1) AND (md5path_2 = :md5_2);";
    LogCvmfs(kLogCatalog, kLogDebug, "Prepared statement catalog %u: %s",
             cat_id, sql_lookup.str().c_str());
    err = sqlite3_prepare_v2(db[cat_id], sql_lookup.str().c_str(), -1, &lookup, NULL);
    if (err != SQLITE_OK) {
      sqlError = "unable to prepare lookup statement";
      return false;
    }

    /* SELECT LOOKUP INODE */
    sqlite3_stmt *lookup_inode;
    ostringstream sql_lookup_inode;
    sql_lookup_inode << "SELECT " << cat_id << ", hash, inode, size, mode, mtime, flags, name, symlink, md5path_1, md5path_2, parent_1, parent_2 "
    "FROM catalog "
    "WHERE rowid = :rowid";
    LogCvmfs(kLogCatalog, kLogDebug, "Prepared statement catalog %u: %s",
             cat_id, sql_lookup_inode.str().c_str());
    err = sqlite3_prepare_v2(db[cat_id], sql_lookup_inode.str().c_str(), -1, &lookup_inode, NULL);
    if (err != SQLITE_OK) {
      sqlError = "unable to prepare lookup statement";
      return false;
    }

    /* SELECT PARENT */
    sqlite3_stmt *parent;
    ostringstream sql_parent;
    sql_parent << "SELECT " << cat_id << ", a.hash, a.inode, a.size, a.mode, a.mtime, a.flags, a.name, a.symlink, a.rowid "
    "FROM catalog a, catalog b "
    "WHERE (b.md5path_1 = :md5_1) AND (b.md5path_2 = :md5_2) AND (a.md5path_1 = b.parent_1) AND (a.md5path_2 = b.parent_2);";
    LogCvmfs(kLogCatalog, kLogDebug, "Prepared statement catalog %u: %s",
          cat_id, sql_parent.str().c_str());
    err = sqlite3_prepare_v2(db[cat_id], sql_parent.str().c_str(), -1, &parent, NULL);
    if (err != SQLITE_OK) {
      sqlError = "unable to prepare parent statement";
      return false;
    }

    /* SELECT LOOKUP NESTED CATAOG */
    sqlite3_stmt *lookup_nested;
    const string sql_lookup_nested = "SELECT sha1 FROM nested_catalogs WHERE path=:path;";
    LogCvmfs(kLogCatalog, kLogDebug, "Prepared statement catalog %u: %s",
             cat_id, sql_lookup_nested.c_str());
    err = sqlite3_prepare_v2(db[cat_id], sql_lookup_nested.c_str(), -1, &lookup_nested, NULL);
    if (err != SQLITE_OK) {
      sqlError = "unable to prepare nested catalog statement";
      return false;
    }

    /* INSERT */
    sqlite3_stmt *insert;
    const string sql_insert = "INSERT INTO catalog "
    "(md5path_1, md5path_2, parent_1, parent_2, hash, inode, size, mode, mtime, flags, name, symlink) "
    "VALUES (:md5_1, :md5_2, :p_1, :p_2, :hash, :ino, :size, :mode, :mtime, :flags, :name, :symlink);";
    LogCvmfs(kLogCatalog, kLogDebug, "Prepared statement catalog %u: %s",
             cat_id, sql_insert.c_str());
    err = sqlite3_prepare_v2(db[cat_id], sql_insert.c_str(), -1, &insert, NULL);
    if (err != SQLITE_OK) {
      sqlError = "unable to prepare insert statement";
      return false;
    }

    /* UPDATE */
    sqlite3_stmt *update;
    const string sql_update = "UPDATE catalog "
    "SET hash = :hash, size = :size, mode = :mode, mtime = :mtime, "
    "flags = :flags, name = :name, symlink = :symlink, inode = :inode "
    "WHERE (md5path_1 = :md5_1) AND (md5path_2 = :md5_2);";
    LogCvmfs(kLogCatalog, kLogDebug, "Prepared statement catalog %u: %s",
             cat_id, sql_update.c_str());
    err = sqlite3_prepare_v2(db[cat_id], sql_update.c_str(), -1, &update, NULL);
    if (err != SQLITE_OK) {
      sqlError = "unable to prepare update statement";
      return false;
    }

    /* UPDATE_INODE */
    sqlite3_stmt *update_inode;
    const string sql_update_inode = "UPDATE catalog "
    "SET hash = :hash, size = :size, mode = coalesce(:mode, mode), mtime = :mtime "
    "WHERE inode = :ino;";
    LogCvmfs(kLogCatalog, kLogDebug, "Prepared statement catalog %u: %s",
             cat_id, sql_update_inode.c_str());
    err = sqlite3_prepare_v2(db[cat_id], sql_update_inode.c_str(), -1, &update_inode, NULL);
    if (err != SQLITE_OK) {
      sqlError = "unable to prepare update statement";
      return false;
    }

    /* UNLINK */
    sqlite3_stmt *unlink;
    const string sql_unlink = "DELETE FROM catalog "
    "WHERE (md5path_1 = :md5_1) AND (md5path_2 = :md5_2);";
    LogCvmfs(kLogCatalog, kLogDebug, "Prepared statement catalog %u: %s",
             cat_id, sql_unlink.c_str());
    err = sqlite3_prepare_v2(db[cat_id], sql_unlink.c_str(), -1, &unlink, NULL);
    if (err != SQLITE_OK) {
      sqlError = "unable to prepare unlink statement";
      return false;
    }

    if (cat_id >= stmts_ls.size()) stmts_ls.push_back(ls);
    else stmts_ls[cat_id] = ls;
    if (cat_id >= stmts_lookup.size()) stmts_lookup.push_back(lookup);
    else stmts_lookup[cat_id] = lookup;
    if (cat_id >= stmts_lookup_inode.size()) stmts_lookup_inode.push_back(lookup_inode);
    else stmts_lookup_inode[cat_id] = lookup_inode;
    if (cat_id >= stmts_parent.size()) stmts_parent.push_back(parent);
    else stmts_parent[cat_id] = parent;
    if (cat_id >= stmts_lookup_nested.size()) stmts_lookup_nested.push_back(lookup_nested);
    else stmts_lookup_nested[cat_id] = lookup_nested;
    if (cat_id >= stmts_insert.size()) stmts_insert.push_back(insert);
    else stmts_insert[cat_id] = insert;
    if (cat_id >= stmts_update.size()) stmts_update.push_back(update);
    else stmts_update[cat_id] = update;
    if (cat_id >= stmts_update_inode.size()) stmts_update_inode.push_back(update_inode);
    else stmts_update_inode[cat_id] = update_inode;
    if (cat_id >= stmts_unlink.size()) stmts_unlink.push_back(unlink);
    else stmts_unlink[cat_id] = unlink;
    return true;
  }