void SEAM::Hide() const {
  for (int s = 0; s < num_splits_; ++s) {
    splits_[s].Hide();
  }
}