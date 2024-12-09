bool Database::Create(const string &filename,
                      const DirectoryEntry &root_entry,
                      const string &root_path)
{
  sqlite3 *sqlite_db;
  SqlDirentInsert *sql_insert;
  Sql *sql_schema;
  int open_flags = SQLITE_OPEN_NOMUTEX | SQLITE_OPEN_READWRITE |
                   SQLITE_OPEN_CREATE;

  // Path hashes
  hash::Md5 root_path_hash = hash::Md5(hash::AsciiPtr(root_path));
  hash::Md5 root_parent_hash;
  if (root_path == "")
    root_parent_hash = hash::Md5();
  else
    root_parent_hash = hash::Md5(hash::AsciiPtr(GetParentPath(root_path)));

  // Create the new catalog file and open it
  LogCvmfs(kLogCatalog, kLogVerboseMsg, "creating new catalog at '%s'",
           filename.c_str());
  if (sqlite3_open_v2(filename.c_str(), &sqlite_db, open_flags, NULL) !=
      SQLITE_OK)
  {
    LogCvmfs(kLogCatalog, kLogStderr,
             "Cannot create and open catalog database file '%s'",
             filename.c_str());
    return false;
  }
  sqlite3_extended_result_codes(sqlite_db, 1);
  Database database(sqlite_db, kLatestSchema, true);

  bool retval;
  string sql;
  retval = Sql(database,
    "CREATE TABLE catalog "
    "(md5path_1 INTEGER, md5path_2 INTEGER, parent_1 INTEGER, parent_2 INTEGER,"
    " hardlinks INTEGER, hash BLOB, size INTEGER, mode INTEGER, mtime INTEGER,"
    " flags INTEGER, name TEXT, symlink TEXT, uid INTEGER, gid INTEGER, "
    " CONSTRAINT pk_catalog PRIMARY KEY (md5path_1, md5path_2));").Execute();
  if (!retval)
    goto create_schema_fail;

  retval = Sql(database,
               "CREATE INDEX idx_catalog_parent "
               "ON catalog (parent_1, parent_2);").Execute();
  if (!retval)
    goto create_schema_fail;

  retval = Sql(database,
    "CREATE TABLE chunks "
    "(md5path_1 INTEGER, md5path_2 INTEGER, offset INTEGER, size INTEGER, "
    " hash BLOB, "
    " CONSTRAINT pk_chunks PRIMARY KEY (md5path_1, md5path_2, offset, size), "
    " FOREIGN KEY (md5path_1, md5path_2) REFERENCES "
    "   catalog(md5path_1, md5path_2));").Execute();
  if (!retval)
    goto create_schema_fail;

  retval = Sql(database,
               "CREATE TABLE properties (key TEXT, value TEXT, "
               "CONSTRAINT pk_properties PRIMARY KEY (key));").Execute();
  if (!retval)
    goto create_schema_fail;

  retval = Sql(database,
               "CREATE TABLE nested_catalogs (path TEXT, sha1 TEXT, "
               "CONSTRAINT pk_nested_catalogs PRIMARY KEY (path));").Execute();
  if (!retval)
    goto create_schema_fail;

  retval = Sql(database, "INSERT INTO properties "
               "(key, value) VALUES ('revision', 0);").Execute();
  if (!retval)
    goto create_schema_fail;

  sql_schema = new Sql(database, "INSERT INTO properties "
                                 "(key, value) VALUES ('schema', :schema);");
  retval = sql_schema->BindDouble(1, kLatestSchema) && sql_schema->Execute();
  delete sql_schema;
  if (!retval)
    goto create_schema_fail;

  retval = Sql(database,
               "CREATE TABLE statistics (counter TEXT, value INTEGER, "
               "CONSTRAINT pk_statistics PRIMARY KEY (counter));").Execute();
  if (!retval)
    goto create_schema_fail;

  retval = Sql(database,
    "INSERT INTO statistics (counter, value) "
    "SELECT 'self_regular', 0 UNION ALL SELECT 'self_symlink', 0 UNION ALL "
    "SELECT 'self_dir', 1 UNION ALL SELECT 'self_nested', 0 UNION ALL "
    "SELECT 'subtree_regular', 0 UNION ALL SELECT 'subtree_symlink', 0 UNION ALL "
    "SELECT 'subtree_dir', 0 UNION ALL SELECT 'subtree_nested', 0;").Execute();
  if (!retval)
    goto create_schema_fail;

  // Insert root entry
  sql_insert = new SqlDirentInsert(database);
  retval = sql_insert->BindPathHash(root_path_hash) &&
           sql_insert->BindParentPathHash(root_parent_hash) &&
           sql_insert->BindDirent(root_entry) &&
           sql_insert->Execute();
  delete sql_insert;
  if (!retval)
    goto create_schema_fail;

  if (root_path != "") {
    retval = Sql(database, "INSERT INTO properties "
      "(key, value) VALUES ('root_prefix', '" + root_path + "');").Execute();
    if (!retval)
      goto create_schema_fail;
  }

  sqlite3_close(sqlite_db);
  return true;

 create_schema_fail:
  LogCvmfs(kLogSql, kLogVerboseMsg, "sql failure %s",
           sqlite3_errmsg(sqlite_db));
  sqlite3_close(sqlite_db);
  return false;
}