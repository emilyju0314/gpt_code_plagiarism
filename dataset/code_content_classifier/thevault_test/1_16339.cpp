void SyncMediator::Add(const SyncItem &entry) {
  if (entry.IsDirectory()) {
    AddDirectoryRecursively(entry);
    return;
  }

  if (entry.IsRegularFile() || entry.IsSymlink()) {
    // A file is a hard link if the link count is greater than 1
    if (entry.HasHardlinks())
      InsertHardlink(entry);
    else
      AddFile(entry);
    return;
  } else if (entry.IsGraftMarker()) {
    LogCvmfs(kLogPublish, kLogDebug, "Ignoring graft marker file.");
    return;  // Ignore markers.
  }

  PrintWarning("'" + entry.GetRelativePath() + "' cannot be added. "
               "Unrecognized file type.");
}