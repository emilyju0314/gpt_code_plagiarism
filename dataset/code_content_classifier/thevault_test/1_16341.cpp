void SyncMediator::Remove(const SyncItem &entry) {
  if (entry.WasDirectory()) {
    RemoveDirectoryRecursively(entry);
    return;
  }

  if (entry.WasRegularFile() || entry.WasSymlink()) {
    RemoveFile(entry);
    return;
  }

  PrintWarning("'" + entry.GetRelativePath() + "' cannot be deleted. "
               "Unrecognized file type.");
}