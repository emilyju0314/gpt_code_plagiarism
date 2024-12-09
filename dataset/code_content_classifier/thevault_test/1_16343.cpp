void SyncMediator::CompleteHardlinks(const SyncItem &entry) {
  assert(handle_hardlinks_);

  // If no hardlink in this directory was changed, we can skip this
  if (GetHardlinkMap().empty())
    return;

  LogCvmfs(kLogPublish, kLogVerboseMsg, "Post-processing hard links in %s",
           entry.GetUnionPath().c_str());

  // Look for legacy hardlinks
  FileSystemTraversal<SyncMediator> traversal(this, union_engine_->union_path(),
                                              false);
  traversal.fn_new_file =
    &SyncMediator::LegacyRegularHardlinkCallback;
  traversal.fn_new_symlink = &SyncMediator::LegacySymlinkHardlinkCallback;
  traversal.Recurse(entry.GetUnionPath());
}