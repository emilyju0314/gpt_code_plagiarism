bool update_inode_internal(const uint64_t inode, const unsigned *mode,
                             const uint64_t size, const time_t mtime,
                             const hash::t_sha1 &checksum)
  {
    enforce_mem_limit();

    bool ret = true;

    pthread_mutex_lock(&mutex);

    //for (int i = 0; i < num_catalogs; ++i)
    //   transaction(i);

    for (int i = 0; i < num_catalogs; ++i) {
      sqlite3_stmt *update_inode = stmts_update_inode[i];

      if (checksum.is_null())
        sqlite3_bind_null(update_inode, 1);
      else
        sqlite3_bind_blob(update_inode, 1, checksum.digest, 20, SQLITE_STATIC);
      sqlite3_bind_int64(update_inode, 2, size);
      if (mode) sqlite3_bind_int(update_inode, 3, *mode);
      else sqlite3_bind_null(update_inode, 3);
      sqlite3_bind_int64(update_inode, 4, mtime);
      sqlite3_bind_int64(update_inode, 5, inode);
      const int rcode = sqlite3_step(update_inode);
      ret &= ((rcode == SQLITE_DONE) || (rcode == SQLITE_OK));
      sqlite3_reset(update_inode);
      //pmesg(D_CATALOG, "update inode %lld in catalog %d resulted in %d, ret is %d", inode, i, rcode, ret);
      if (!ret) break;
    }
    //if (ret) {
    //   for (int i = 0; i < num_catalogs; i++)
    //      commit(i);
    //} else {
    //   for (int i = 0; i < num_catalogs; i++)
    //      rollback(i);
    //}

    pthread_mutex_unlock(&mutex);

    return ret;
  }