bool merge(const string &nested_dir) {
      enforce_mem_limit();
      
      int result = false;
      t_dirent dir;
      t_dirent nest;
      int src_id = -1;
      const hash::t_md5 md5(nested_dir);
      
      pthread_mutex_lock(&mutex);
      
      pmesg(D_CATALOG, "merging at path %s", mangled_path(nested_dir).c_str());
      
      /* First: nested root becomes a normal directory */
      if (lookup_unprotected(md5, dir) &&
          unlink_unprotected(md5, dir.catalog_id) &&
          lookup_unprotected(md5, nest))
      {
         src_id = dir.catalog_id;
         dir.catalog_id = nest.catalog_id;
         dir.flags = DIR;
         pmesg(D_CATALOG, "figured out parent catalog (%d) and nested catalog (%d)", nest.catalog_id, src_id);
         if (update_unprotected(md5, dir)) {
            const string cat_file = get_catalog_file(src_id);
            detach(src_id);
            if (src_id < dir.catalog_id) dir.catalog_id--;
            pmesg(D_CATALOG, "try to merge from %s into id %d", cat_file.c_str(), dir.catalog_id);
            if (sql_exec(db[dir.catalog_id], "ATTACH '" + cat_file + "' AS nested;")) 
            {
               const string sql_merge = "INSERT INTO main.catalog "
                  "SELECT * FROM nested.catalog; "
                  "DELETE FROM nested.catalog; "
                  "INSERT INTO main.chunks "
                  "SELECT * FROM main.chunks; "
                  "DELETE FROM nested.chunks; " 
                  "DELETE FROM main.nested_catalogs "
                     "WHERE path = '" + nested_dir + "'; "
                  "INSERT INTO main.nested_catalogs "
                     "SELECT * FROM nested.nested_catalogs; "
                  "DELETE FROM nested.nested_catalogs;";
               pmesg(D_CATALOG, "merge prerquisits sucessful, moving mere data:\n%s", sql_merge.c_str());

               if (sql_exec(db[dir.catalog_id], sql_merge)) {
                  pmesg(D_CATALOG, "merge data moved");
                  result = sql_exec(db[dir.catalog_id], "DETACH nested;");
               }
            } else {
               pmesg(D_CATALOG, "Attache failed: %s", get_sql_error().c_str());
            }
         }
      }
      
      pthread_mutex_unlock(&mutex);
      return result;
   }