bool vacuum() {
      int result = true;
        
      for (int i = 0; i < num_catalogs; i++) {
         pmesg(D_CATALOG, "trying vacuum %s", get_catalog_file(i).c_str());
         if (!sql_exec(db[i], "VACUUM;"))
            result = false;
      }
      
      return result;
   }