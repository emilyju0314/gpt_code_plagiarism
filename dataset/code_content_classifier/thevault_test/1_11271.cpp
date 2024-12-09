std::vector<std::string> String_vector_to_vector(
    const struct String_vector* strings) {
  std::vector<std::string> ret;
  for (size_t i = 0;i < (size_t)(strings->count); ++i) {
    ret.push_back(strings->data[i]);
  }
  return ret;
}