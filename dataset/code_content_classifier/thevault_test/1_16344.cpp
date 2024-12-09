void SyncMediator::RemoveDirectory(const SyncItem &entry) {
  const std::string directory_path = entry.GetRelativePath();

  if (catalog_manager_->IsTransitionPoint(directory_path)) {
    RemoveNestedCatalog(entry);
  }

  PrintChangesetNotice(kRemove, entry.GetUnionPath());
  if (!params_->dry_run) {
    catalog_manager_->RemoveDirectory(directory_path);
  }
}