bool init(const uid_t puid, const gid_t pgid) {
    uid = puid;
    gid = pgid;
    root_prefix = "";
    num_catalogs = current_catalog = 0;
    return initTLS();
  }