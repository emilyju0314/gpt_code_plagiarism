void BoxWord::ComputeBoundingBox() {
  bbox_ = TBOX();
  for (unsigned i = 0; i < length_; ++i) {
    bbox_ += boxes_[i];
  }
}