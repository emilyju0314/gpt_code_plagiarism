bool SignatureManager::LoadBlacklist(
  const std::string &path_blacklist,
  bool append)
{
  LogCvmfs(kLogSignature, kLogDebug, "reading from blacklist %s",
           path_blacklist.c_str());
  if (!append)
    blacklisted_certificates_.clear();

  char *buffer;
  unsigned buffer_size;
  if (!CopyPath2Mem(path_blacklist,
                    reinterpret_cast<unsigned char **>(&buffer), &buffer_size))
  {
    return false;
  }

  unsigned num_bytes = 0;
  while (num_bytes < buffer_size) {
    const string fingerprint = GetLineMem(buffer + num_bytes,
                                          buffer_size - num_bytes);
    blacklisted_certificates_.push_back(fingerprint);
    num_bytes += fingerprint.length() + 1;
  }
  free(buffer);

  return true;
}