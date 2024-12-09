int lookup_catalogid_unprotected(const hash::t_md5 &key) {
      enforce_mem_limit();
      
      int catalog_id = -1;
      
      for (int i = 0; i < num_catalogs; ++i) {
         sqlite3_stmt *stmt_lookup = stmts_lookup[(current_catalog + i) % num_catalogs];
         int flags = 0;
      
         sqlite3_bind_int64(stmt_lookup, 1, *((sqlite_int64 *)(&key.digest[0])));
         sqlite3_bind_int64(stmt_lookup, 2, *((sqlite_int64 *)(&key.digest[8])));
         if (sqlite3_step(stmt_lookup) == SQLITE_ROW) {
            flags = sqlite3_column_int(stmt_lookup, 6);
            catalog_id = sqlite3_column_int(stmt_lookup, 0);
         }
         sqlite3_reset(stmt_lookup);
         /* Always preferr root from nested catalog */
         if (flags & catalog::DIR_NESTED_ROOT)
            break;
      }
      
      return catalog_id;
   }