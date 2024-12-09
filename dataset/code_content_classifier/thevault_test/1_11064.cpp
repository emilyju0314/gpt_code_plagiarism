void BoxWord::InsertBox(unsigned index, const TBOX &box) {
  if (index < length_) {
    boxes_.insert(boxes_.begin() + index, box);
  } else {
    boxes_.push_back(box);
  }
  length_ = boxes_.size();
  ComputeBoundingBox();
}