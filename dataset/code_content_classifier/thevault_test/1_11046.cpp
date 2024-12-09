int DetLineFit::NumberOfMisfittedPoints(double threshold) const {
  int num_misfits = 0;
  int num_dists = distances_.size();
  // Get the absolute values of the errors.
  for (int i = 0; i < num_dists; ++i) {
    if (distances_[i].key() > threshold) {
      ++num_misfits;
    }
  }
  return num_misfits;
}