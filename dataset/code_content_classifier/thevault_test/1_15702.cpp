bool parent_unprotected(const hash::t_md5 &key, t_dirent &result) {
      enforce_mem_limit();
      
      bool found = false;
      
      for (int i = 0; i < num_catalogs; ++i) {
         sqlite3_stmt *stmt_parent = stmts_parent[(current_catalog + i) % num_catalogs];
         
         sqlite3_bind_int64(stmt_parent, 1, *((sqlite_int64 *)(&key.digest[0])));
         sqlite3_bind_int64(stmt_parent, 2, *((sqlite_int64 *)(&key.digest[8])));
         if (sqlite3_step(stmt_parent) == SQLITE_ROW) {
            int flags = sqlite3_column_int(stmt_parent, 6);
            /* If we hit the nested catalog entry, we are in the wrong catalog. Too bad. */
            if (!(flags & catalog::DIR_NESTED)) { 
               result.catalog_id = sqlite3_column_int(stmt_parent, 0); 
               result.name = string((char *)sqlite3_column_text(stmt_parent, 7));
               result.symlink = string((char *)sqlite3_column_text(stmt_parent, 8));
               result.flags = flags;
               result.inode = sqlite3_column_int64(stmt_parent, 2); 
               result.mode = sqlite3_column_int(stmt_parent, 4);
               result.size = sqlite3_column_int64(stmt_parent, 3);
               result.mtime = sqlite3_column_int64(stmt_parent, 5);
               //result.checksum = hash::t_sha1();
               found = true;
            }
         }
         sqlite3_reset(stmt_parent);
         if (found) {
            current_catalog = (current_catalog + i) % num_catalogs;
            break;
         }
      }
      
      return found;
   }