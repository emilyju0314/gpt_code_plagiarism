void SEAM::Print(const char *label) const {
  tprintf("%s", label);
  tprintf(" %6.2f @ (%d,%d), p=%u, n=%u ", priority_, location_.x, location_.y, widthp_, widthn_);
  for (int s = 0; s < num_splits_; ++s) {
    splits_[s].Print();
    if (s + 1 < num_splits_) {
      tprintf(",   ");
    }
  }
  tprintf("\n");
}