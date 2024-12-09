void BoxWord::DeleteBox(unsigned index) {
  ASSERT_HOST(index < length_);
  boxes_.erase(boxes_.begin() + index);
  --length_;
  ComputeBoundingBox();
}