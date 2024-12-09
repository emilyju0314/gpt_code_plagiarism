double DetLineFit::ComputeUpperQuartileError() {
  int num_errors = distances_.size();
  if (num_errors == 0) {
    return 0.0;
  }
  // Get the absolute values of the errors.
  for (int i = 0; i < num_errors; ++i) {
    if (distances_[i].key() < 0) {
      distances_[i].key() = -distances_[i].key();
    }
  }
  // Now get the upper quartile distance.
  auto index = 3 * num_errors / 4;
  std::nth_element(distances_.begin(), distances_.begin() + index, distances_.end());
  double dist = distances_[index].key();
  // The true distance is the square root of the dist squared / square_length.
  // Don't bother with the square root. Just return the square distance.
  return square_length_ > 0.0 ? dist * dist / square_length_ : 0.0;
}