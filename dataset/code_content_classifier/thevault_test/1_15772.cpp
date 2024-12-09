bool CommandCheck::Exists(const string &file) {
  if (remote_repository == NULL)
    return FileExists(file);
  else {
    const string url = *remote_repository + "/" + file;
    download::JobInfo head(&url, false);
    return download::Fetch(&head) == download::kFailOk;
  }
}