void SEAM::Reveal() const {
  for (int s = 0; s < num_splits_; ++s) {
    splits_[s].Reveal();
  }
}