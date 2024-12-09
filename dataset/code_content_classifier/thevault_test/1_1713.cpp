static bool IsRealDirectory(const char* path) {
  if (path == NULL) return false;

  struct stat dirinfo;
  if (lstat(path, &dirinfo) != 0) {
    return false;
  }

  return (S_ISDIR(dirinfo.st_mode)) &&
     (!(S_ISLNK(dirinfo.st_mode)));
}