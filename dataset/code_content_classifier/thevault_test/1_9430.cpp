void AppendSubstring(const char *start, size_t len,
                     std::vector<Substring> *list) {
  if (!list->empty() && list->back().start + list->back().len == start) {
    // Merge with previous line.
    list->back().len += len;
  } else {
    list->push_back(Substring(start, len));
  }
}