size_t GetIndex(const std::vector<NetLogEntry>& entries, int offset) {
  if (offset >= 0)
    return static_cast<size_t>(offset);

  size_t abs_offset = static_cast<size_t>(-offset);
  // If offset indicates a position before the start of the array, just return
  // the end of the list.
  if (abs_offset > entries.size())
    return entries.size();
  return entries.size() - abs_offset;
}