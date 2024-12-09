static TBOX ComputeWordBounds(const tesseract::PointerVector<WERD_RES> &words,
                              int w_index, TBOX prev_box, WERD_RES_IT w_it) {
  constexpr int kSignificantOverlapFraction = 4;
  TBOX clipped_box;
  TBOX current_box = words[w_index]->word->bounding_box();
  TBOX next_box;
  if (static_cast<size_t>(w_index + 1) < words.size() &&
      words[w_index + 1] != nullptr && words[w_index + 1]->word != nullptr) {
    next_box = words[w_index + 1]->word->bounding_box();
  }
  for (w_it.forward(); !w_it.at_first() && w_it.data()->part_of_combo;
       w_it.forward()) {
    if (w_it.data() == nullptr || w_it.data()->word == nullptr) {
      continue;
    }
    TBOX w_box = w_it.data()->word->bounding_box();
    int height_limit = std::min<int>(w_box.height(), w_box.width() / 2);
    int width_limit = w_box.width() / kSignificantOverlapFraction;
    int min_significant_overlap = std::max(height_limit, width_limit);
    int overlap = w_box.intersection(current_box).width();
    int prev_overlap = w_box.intersection(prev_box).width();
    int next_overlap = w_box.intersection(next_box).width();
    if (overlap > min_significant_overlap) {
      if (prev_overlap > min_significant_overlap) {
        // We have no choice but to use the LSTM word edge.
        clipped_box.set_left(current_box.left());
      } else if (next_overlap > min_significant_overlap) {
        // We have no choice but to use the LSTM word edge.
        clipped_box.set_right(current_box.right());
      } else {
        clipped_box += w_box;
      }
    }
  }
  if (clipped_box.height() <= 0) {
    clipped_box.set_top(current_box.top());
    clipped_box.set_bottom(current_box.bottom());
  }
  if (clipped_box.width() <= 0) {
    clipped_box = current_box;
  }
  return clipped_box;
}