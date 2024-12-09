float SEAM::FullPriority(int xmin, int xmax, double overlap_knob, int centered_maxwidth,
                         double center_knob, double width_change_knob) const {
  if (num_splits_ == 0) {
    return 0.0f;
  }
  for (int s = 1; s < num_splits_; ++s) {
    splits_[s].SplitOutline();
  }
  float full_priority =
      priority_ + splits_[0].FullPriority(xmin, xmax, overlap_knob, centered_maxwidth, center_knob,
                                          width_change_knob);
  for (int s = num_splits_ - 1; s >= 1; --s) {
    splits_[s].UnsplitOutlines();
  }
  return full_priority;
}