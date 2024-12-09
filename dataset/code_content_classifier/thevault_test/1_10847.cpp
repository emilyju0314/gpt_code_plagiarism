TBOX SEAM::bounding_box() const {
  TBOX box(location_.x, location_.y, location_.x, location_.y);
  for (int s = 0; s < num_splits_; ++s) {
    box += splits_[s].bounding_box();
  }
  return box;
}