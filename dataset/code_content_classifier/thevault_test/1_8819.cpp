void check_path(const std::string& path, bool* is_file, bool* is_dir) {
  struct stat path_stat;
  stat(path.c_str(), &path_stat);
  *is_file = S_ISREG(path_stat.st_mode);
  *is_dir  = S_ISDIR(path_stat.st_mode);
}