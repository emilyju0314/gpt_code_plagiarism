int BoxChar::TotalByteLength(const std::vector<BoxChar *> &boxes) {
  int total_length = 0;
  for (auto boxe : boxes) {
    total_length += boxe->ch_.size();
  }
  return total_length;
}