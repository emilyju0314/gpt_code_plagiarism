string CreateTempDir(const std::string &path_prefix) {
  string dir = path_prefix + ".XXXXXX";
  char *tmp_dir = strdupa(dir.c_str());
  tmp_dir = mkdtemp(tmp_dir);
  if (tmp_dir == NULL)
    return "";
  return string(tmp_dir);
}