bool detach_intermediate(const unsigned cat_id) {
      pmesg(D_CATALOG, "detach intermediate catalog %d", cat_id);
      
      if (stmts_lookup_chunk[cat_id]) {
         sqlite3_finalize(stmts_lookup_chunk[cat_id]);
         stmts_lookup_chunk[cat_id] = NULL;
      }
      if (stmts_rmino_chunk[cat_id]) {
         sqlite3_finalize(stmts_rmino_chunk[cat_id]);
         stmts_rmino_chunk[cat_id] = NULL;
      }
      if (stmts_rm_chunk[cat_id]) {
         sqlite3_finalize(stmts_rm_chunk[cat_id]);
         stmts_rm_chunk[cat_id] = NULL;
      }
      if (stmts_ins_chunk[cat_id]) {
         sqlite3_finalize(stmts_ins_chunk[cat_id]);
         stmts_ins_chunk[cat_id] = NULL;
      }
      if (stmts_unlink[cat_id]) {
         sqlite3_finalize(stmts_unlink[cat_id]);
         stmts_unlink[cat_id] = NULL;
      }
      if (stmts_update_inode[cat_id]) {
         sqlite3_finalize(stmts_update_inode[cat_id]);
         stmts_update_inode[cat_id] = NULL;
      }
      if (stmts_update[cat_id]) {
         sqlite3_finalize(stmts_update[cat_id]);
         stmts_update[cat_id] = NULL;
      }
      if (stmts_insert[cat_id]) {
         sqlite3_finalize(stmts_insert[cat_id]);
         stmts_insert[cat_id] = NULL;
      }
      if (stmts_ls[cat_id]) {
         sqlite3_finalize(stmts_ls[cat_id]);
         stmts_ls[cat_id] = NULL;
      }
      if (stmts_parent[cat_id]) {
         sqlite3_finalize(stmts_parent[cat_id]);
         stmts_parent[cat_id] = NULL;
      }
      if (stmts_lookup[cat_id]) {
         sqlite3_finalize(stmts_lookup[cat_id]);
         stmts_lookup[cat_id] = NULL;
      }
      if (stmts_lookup_inode[cat_id]) {
         sqlite3_finalize(stmts_lookup_inode[cat_id]);
         stmts_lookup_inode[cat_id] = NULL;
      }
      in_transaction[cat_id] = false;

      pmesg(D_CATALOG, "detach intermediate %d, statements removed, closing db", cat_id);
      const int result = sqlite3_close(db[cat_id]);
      if (result == SQLITE_OK) {
         db[cat_id] = NULL;
         return true;
      } else return false;
   }