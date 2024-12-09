void fini() {
      for (int i = 0; i < num_catalogs; ++i)
         detach_intermediate(i);
           
      stmts_lookup_chunk.clear();
      stmts_rmino_chunk.clear();
      stmts_rm_chunk.clear();
      stmts_ins_chunk.clear();
      stmts_unlink.clear();
      stmts_update_inode.clear();
      stmts_update.clear();
      stmts_insert.clear();
      stmts_ls.clear();
      stmts_parent.clear();
      stmts_lookup.clear();
      stmts_lookup_inode.clear();
      
      catalog_urls.clear();
      catalog_files.clear();
      
      root_prefix = "";
      uid = gid = 0;
      num_catalogs = current_catalog = 0;
      pthread_key_delete(pkey_sqlitemem);
   }