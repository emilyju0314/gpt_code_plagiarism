bool make_ls(const string &path, const string &filename) {
    vector<t_dirent> entries = ls_unprotected(path);

    if (!attach(filename, "", false, true))
      return false;

    const hash::t_md5 md5_parent(path);
    unsigned i;
    for (i = 0; i < entries.size(); ++i) {
      const hash::t_md5 md5(path + "/" + entries[i].name);
      entries[i].catalog_id = num_catalogs-1;
      if (!insert_unprotected(md5, md5_parent, entries[i]))
        break;
    }
    if ((entries.size() > 0) && (i != entries.size()))
      return false;

    commit(num_catalogs-1);
    if (!detach(num_catalogs-1))
      return false;

    return true;
  }