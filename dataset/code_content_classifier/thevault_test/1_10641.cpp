bool BoxChar::MostlyVertical(const std::vector<BoxChar *> &boxes) {
  int64_t total_dx = 0, total_dy = 0;
  for (size_t i = 1; i < boxes.size(); ++i) {
    if (boxes[i - 1]->box_ != nullptr && boxes[i]->box_ != nullptr &&
        boxes[i - 1]->page_ == boxes[i]->page_) {
      int dx = boxes[i]->box_->x - boxes[i - 1]->box_->x;
      int dy = boxes[i]->box_->y - boxes[i - 1]->box_->y;
      if (abs(dx) > abs(dy) * kMinNewlineRatio || abs(dy) > abs(dx) * kMinNewlineRatio) {
        total_dx += dx * dx;
        total_dy += dy * dy;
      }
    }
  }
  return total_dy > total_dx;
}