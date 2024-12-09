bool attach(const string &db_file, const string &url, 
               const bool read_only, const bool open_transaction) 
   {
		sqlite3 *new_db;
      int flags = SQLITE_OPEN_NOMUTEX;
      if (read_only)
         flags |= SQLITE_OPEN_READONLY;
      else
         flags |= SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;
      
      pmesg(D_CATALOG, "Attaching %s as id %d", db_file.c_str(), num_catalogs);
      if (sqlite3_open_v2(db_file.c_str(), &new_db, flags, NULL) != SQLITE_OK) {
         sqlite3_close(new_db);
         pmesg(D_CATALOG, "Cannot attach file %s as id %d", db_file.c_str(), num_catalogs);
         goto attach_return;
      }
      db.push_back(new_db);
      sqlite3_extended_result_codes(db[num_catalogs], 1);
      in_transaction.push_back(false);
      opened_read_only.push_back(read_only);
      
      if (!read_only) {
         if (!sql_exec(db[num_catalogs], "PRAGMA synchronous=0; PRAGMA auto_vacuum=1;"))
            goto attach_return;
      }
      
      pmesg(D_CATALOG, "Creating / Checking DB in %s", db_file.c_str());
      if (!create_db(num_catalogs, read_only)) {
         sqlite3_close(db[num_catalogs]);
         goto attach_return;
      }
      
      if (!build_prepared_stmts(num_catalogs)) {
         sqlite3_close(db[num_catalogs]);
         goto attach_return;
      }
      
      /* For db0: get root prefix */
      if (num_catalogs == 0) {
         sqlite3_stmt *stmt_rprefix; 
         int err = sqlite3_prepare(db[0], "SELECT value FROM properties WHERE key='root_prefix';",
            -1, &stmt_rprefix, NULL);
         if (err != SQLITE_OK)
            goto attach_fail;
         err = sqlite3_step(stmt_rprefix);
         if (err == SQLITE_ROW) {
            root_prefix = string((char *)sqlite3_column_text(stmt_rprefix, 0));
            pmesg(D_CATALOG, "found root prefix %s", root_prefix.c_str());
         }
         sqlite3_finalize(stmt_rprefix);
      }
   
      catalog_urls.push_back(url);
      catalog_files.push_back(db_file);
   
      current_catalog = num_catalogs;
      num_catalogs++;
      
      if (open_transaction) transaction(num_catalogs-1);
      
      return true;
      
   attach_fail:
      detach_intermediate(num_catalogs);
   attach_return:
      return false;
   }