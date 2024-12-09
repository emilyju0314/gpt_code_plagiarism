bool register_nested(const unsigned cat_id, const string &path) {
      enforce_mem_limit();
      
      int result = true;
      
      sqlite3_stmt *stmt_register;
      const string sql = "INSERT INTO nested_catalogs (path) VALUES (:p);";
      const int err = sqlite3_prepare_v2(db[cat_id], sql.c_str(), -1, &stmt_register, NULL);
      if (err != SQLITE_OK) {
         sqlError = "unable to prepare register nested catalog statement";
         result = false;
      } else {
         sqlite3_bind_text(stmt_register, 1, &path[0], path.length(), SQLITE_STATIC);
         const int rcode = sqlite3_step(stmt_register); 
         result = ((rcode == SQLITE_DONE) || (rcode == SQLITE_OK));
         sqlite3_finalize(stmt_register);
      }
      
      return result;
   }