ErrorMessageOr<bool> IsInodeInMapsFile(ino_t inode, pid_t pid) {
  OUTCOME_TRY(auto&& maps_contents,
              orbit_base::ReadFileToString(absl::StrFormat("/proc/%d/maps", pid)));

  std::vector<std::string_view> lines = absl::StrSplit(maps_contents, '\n');

  for (const auto& line : lines) {
    std::vector<std::string_view> fields = absl::StrSplit(line, ' ', absl::SkipEmpty{});
    constexpr int kInodeFieldIndex = 4;
    if (fields.size() <= kInodeFieldIndex) continue;

    ino_t current_inode{};
    if (!absl::SimpleAtoi(fields[kInodeFieldIndex], &current_inode)) continue;
    if (current_inode == inode) return true;
  }

  return false;
}