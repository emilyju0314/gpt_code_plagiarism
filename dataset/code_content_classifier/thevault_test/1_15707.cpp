static bool sql_exec(sqlite3 * const db, const string &sql) {
    enforce_mem_limit();

    char *errMsg = NULL;
    int err = sqlite3_exec(db, sql.c_str(), NULL, NULL, &errMsg);
    if (err != SQLITE_OK) {
      ostringstream str_err;
      str_err << errMsg << " (" << err << ")";
      sqlError = str_err.str();
      sqlite3_free(errMsg);
      return false;
    }
    if (errMsg) free(errMsg);
    return true;
  }