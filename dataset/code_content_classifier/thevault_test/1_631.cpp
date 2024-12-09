void Database::exec(const char *sql) const {
  char *err;
  const int exit = sqlite3_exec(Database::m_db, sql, nullptr, 0, &err);

  if (exit != SQLITE_OK) {
    std::cerr << "Failed to Execute Query :: " << err << "\n";
    sqlite3_free(err);
  } else {
    LOG("Query Executed Successfully");
  }
}