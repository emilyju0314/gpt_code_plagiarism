bool ApacheConfig::MakeAbsolutePath(std::string* path) {
  if (path->length() == 0) {
    return false;
  }

  if ((*path)[0] != '/') {
    if (serverroot_.length() == 0) {
      return false;
    } else {
      *path = serverroot_ + "/" + *path;
    }
  }
  return true;
}