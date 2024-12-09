void SEAM::Mark(ScrollView *window) const {
  for (int s = 0; s < num_splits_; ++s) {
    splits_[s].Mark(window);
  }
}