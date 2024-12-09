Database::Database(sqlite3 *sqlite_db, const float schema, const bool rw) {
  sqlite_db_ = sqlite_db;
  filename_ = "TMP";
  schema_version_ = schema;
  read_write_ = rw;
  ready_ = false;  // Don't close on delete
}