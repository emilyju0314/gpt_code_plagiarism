int64_t AcsContacted() {
  struct stat stat_buf;
  memset(&stat_buf, 0, sizeof(stat_buf));
  if (stat(acs_contact_file.c_str(), &stat_buf) < 0)
    return 0;
  return stat_buf.st_mtime;
}