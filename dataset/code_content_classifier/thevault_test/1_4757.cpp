std::string _format_non_converging_batches(const std::vector<int64_t>& batches) {
  std::stringstream ss;
  const int too_long = 5;

  ss << "batches ";
  if (batches.size() <= too_long) {
    for (const auto i : c10::irange(batches.size() - 1)) {
      ss << batches[i] << ", ";
    }
    ss << batches.back();
  } else {
    for (const auto i : c10::irange(too_long)) {
      ss << batches[i] << ", ";
    }
    ss << "and other " << batches.size() - too_long << " batches";
  }

  return ss.str();
}