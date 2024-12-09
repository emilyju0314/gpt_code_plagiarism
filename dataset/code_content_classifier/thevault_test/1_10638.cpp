void BoxChar::InsertSpaces(bool rtl_rules, bool vertical_rules, std::vector<BoxChar *> *boxes) {
  // After InsertNewlines, any remaining null boxes are not newlines, and are
  // singletons, so add a box to each remaining null box.
  for (size_t i = 1; i + 1 < boxes->size(); ++i) {
    Box *box = (*boxes)[i]->box_;
    if (box == nullptr) {
      Box *prev = (*boxes)[i - 1]->box_;
      Box *next = (*boxes)[i + 1]->box_;
      ASSERT_HOST(prev != nullptr && next != nullptr);
      int top = std::min(prev->y, next->y);
      int bottom = std::max(prev->y + prev->h, next->y + next->h);
      int left = prev->x + prev->w;
      int right = next->x;
      if (vertical_rules) {
        top = prev->y + prev->h;
        bottom = next->y;
        left = std::min(prev->x, next->x);
        right = std::max(prev->x + prev->w, next->x + next->w);
      } else if (rtl_rules) {
        // With RTL we have to account for BiDi.
        // Right becomes the min left of all prior boxes back to the first
        // space or newline.
        right = prev->x;
        left = next->x + next->w;
        for (int j = i - 2; j >= 0 && (*boxes)[j]->ch_ != " " && (*boxes)[j]->ch_ != "\t"; --j) {
          prev = (*boxes)[j]->box_;
          ASSERT_HOST(prev != nullptr);
          if (prev->x < right) {
            right = prev->x;
          }
        }
        // Left becomes the max right of all next boxes forward to the first
        // space or newline.
        for (size_t j = i + 2;
             j < boxes->size() && (*boxes)[j]->box_ != nullptr && (*boxes)[j]->ch_ != "\t"; ++j) {
          next = (*boxes)[j]->box_;
          if (next->x + next->w > left) {
            left = next->x + next->w;
          }
        }
      }
      // Italic and stylized characters can produce negative spaces, which
      // Leptonica doesn't like, so clip to a positive size.
      if (right <= left) {
        right = left + 1;
      }
      if (bottom <= top) {
        bottom = top + 1;
      }
      (*boxes)[i]->AddBox(left, top, right - left, bottom - top);
      (*boxes)[i]->ch_ = " ";
    }
  }
}