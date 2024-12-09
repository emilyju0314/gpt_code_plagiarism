bool ApacheConfig::RetrieveFiles(const char* fname,
                                 std::vector<std::string>* files) {
  std::string filename(fname);
  if (!MakeAbsolutePath(&filename)) {
    return false;
  }

  // a regular file with no regex in name
  if (!IsFnmatchPattern(filename.c_str())
      && !IsRealDirectory(filename.c_str())) {
    files->push_back(filename.c_str());
    return true;
  }

  std::string dirname, pattern;
  if (IsRealDirectory(filename.c_str())) {
    dirname = filename;
  } else {
    // fname should be an absolute path
    size_t pos = filename.rfind('/');
    if (pos == std::string::npos) return false;

    // separate dir and file name pattern
    dirname = filename.substr(0, pos);
    pattern = filename.substr(pos + 1);
  }

  DIR* dir = opendir(dirname.c_str());
  if (dir == NULL) return false;

  // iterate the dir to match file pattern
  struct dirent* entry = readdir(dir);
  while (entry != NULL) {
    if (entry->d_name != NULL &&
        strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
      if (pattern.length() == 0 ||
          fnmatch(pattern.c_str(), entry->d_name, FNM_PERIOD)  == 0) {
        std::string fullpath(dirname);
        fullpath.append("/").append(entry->d_name);
        if (IsRealDirectory(fullpath.c_str())) {
          RetrieveFiles(fullpath.c_str(), files);
        } else {
          files->push_back(fullpath);
        }
      }
    }

    entry = readdir(dir);
  }
  closedir(dir);

  return true;
}