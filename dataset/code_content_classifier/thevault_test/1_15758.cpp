static bool Exists(const string &repository, const string &file) {
  if (IsRemote(repository)) {
    const string url = repository + "/" + file;
    download::JobInfo head(&url, false);
    return download::Fetch(&head) == download::kFailOk;
  } else {
    return FileExists(file);
  }
}