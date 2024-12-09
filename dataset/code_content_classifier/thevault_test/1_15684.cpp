static bool create_db(const unsigned cat_id, const bool read_only) {      
      const string sql_catalog = "CREATE TABLE IF NOT EXISTS catalog "
         "(md5path_1 INTEGER, md5path_2 INTEGER, parent_1 INTEGER, parent_2 INTEGER, inode INTEGER, "
         "hash BLOB, size INTEGER, mode INTEGER, mtime INTEGER, flags INTEGER, name TEXT, symlink TEXT, "
         "CONSTRAINT pk_catalog PRIMARY KEY (md5path_1, md5path_2));";
      if (!sql_exec(db[cat_id], sql_catalog))
         return false;
      
      const string sql_index = "CREATE INDEX IF NOT EXISTS idx_catalog_parent "
         "ON catalog (parent_1, parent_2);";
      if (!sql_exec(db[cat_id], sql_index))
         return false;
         
      const string sql_index_ino = "CREATE INDEX IF NOT EXISTS idx_catalog_inode "
         "ON catalog (inode);";
      if (!sql_exec(db[cat_id], sql_index_ino))
         return false;
   
      const string sql_props = "CREATE TABLE IF NOT EXISTS properties "
         "(key TEXT, value TEXT, CONSTRAINT pk_properties PRIMARY KEY (key));";
      if (!sql_exec(db[cat_id], sql_props))
         return false;   
         
      const string sql_nested = "CREATE TABLE IF NOT EXISTS nested_catalogs "
         "(path TEXT, sha1 TEXT, CONSTRAINT pk_nested_catalogs PRIMARY KEY (path));";
      if (!sql_exec(db[cat_id], sql_nested))
         return false;
      
      /* Schema extensions */
      if (!read_only) {
         /* Added from schema 1.0 --> 2.0 */
         const string sql_chunks = "CREATE TABLE IF NOT EXISTS chunks "
            "(md5path_1 INTEGER, md5path_2 INTEGER, inode INTEGER, offset INTEGER, hash BLOB,"
            "CONSTRAINT pk_chunks PRIMARY KEY (md5path_1, md5path_2, offset));";
         if (!sql_exec(db[cat_id], sql_chunks))
            return false;
         
         const string sql_index_chunks_ino = "CREATE INDEX IF NOT EXISTS idx_chunks_inode "
            "ON chunks (inode);";
         if (!sql_exec(db[cat_id], sql_index_chunks_ino))
            return false;
      
         const string sql_schema = "INSERT OR REPLACE INTO properties (key, value) VALUES ('schema', '2.0');";
         if (!sql_exec(db[cat_id], sql_schema))
            return false;   
      }
   
      return true;
   }