void BoxWord::MergeBoxes(unsigned start, unsigned end) {
  start = ClipToRange(start, 0U, length_);
  end = ClipToRange(end, 0U, length_);
  if (end <= start + 1) {
    return;
  }
  for (unsigned i = start + 1; i < end; ++i) {
    boxes_[start] += boxes_[i];
  }
  int shrinkage = end - 1 - start;
  length_ -= shrinkage;
  for (unsigned i = start + 1; i < length_; ++i) {
    boxes_[i] = boxes_[i + shrinkage];
  }
  boxes_.resize(length_);
}