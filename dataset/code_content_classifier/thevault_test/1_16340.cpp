void SyncMediator::Touch(const SyncItem &entry) {
  if (entry.IsGraftMarker()) {return;}
  if (entry.IsDirectory()) {
    TouchDirectory(entry);
    return;
  }

  if (entry.IsRegularFile() || entry.IsSymlink()) {
    Replace(entry);  // This way, hardlink processing is correct
    return;
  }

  PrintWarning("'" + entry.GetRelativePath() + "' cannot be touched. "
               "Unrecognied file type.");
}