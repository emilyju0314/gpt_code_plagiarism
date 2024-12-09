bool CommandCheck::Exists(const string &file)
{
  if (!is_remote_) {
    return FileExists(file) || SymlinkExists(file);
  } else {
    const string url = repo_base_path_ + "/" + file;
    download::JobInfo head(&url, false);
    return download_manager()->Fetch(&head) == download::kFailOk;
  }
}