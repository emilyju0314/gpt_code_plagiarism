void BoxChar::InsertNewlines(bool rtl_rules, bool vertical_rules, std::vector<BoxChar *> *boxes) {
  size_t prev_i = SIZE_MAX;
  int max_shift = 0;
  for (size_t i = 0; i < boxes->size(); ++i) {
    Box *box = (*boxes)[i]->box_;
    if (box == nullptr) {
      if (prev_i == SIZE_MAX || prev_i + 1 < i || i + 1 == boxes->size()) {
        // Erase null boxes at the start of a line and after another null box.
        do {
          delete (*boxes)[i];
          boxes->erase(boxes->begin() + i);
          if (i == 0) {
            break;
          }
        } while (i-- == boxes->size() && (*boxes)[i]->box_ == nullptr);
      }
      continue;
    }
    if (prev_i != SIZE_MAX) {
      Box *prev_box = (*boxes)[prev_i]->box_;
      int shift = box->x - prev_box->x;
      if (vertical_rules) {
        shift = box->y - prev_box->y;
      } else if (rtl_rules) {
        shift = -shift;
      }
      if (-shift > max_shift) {
        // This is a newline. Since nothing cares about the size of the box,
        // except the out-of-bounds checker, minimize the chance of creating
        // a box outside the image by making the width and height 1.
        int width = 1;
        int height = 1;
        int x = prev_box->x + prev_box->w;
        int y = prev_box->y;
        if (vertical_rules) {
          x = prev_box->x;
          y = prev_box->y + prev_box->h;
        } else if (rtl_rules) {
          x = prev_box->x - width;
          if (x < 0) {
            tprintf("prev x = %d, width=%d\n", prev_box->x, width);
            x = 0;
          }
        }
        if (prev_i + 1 == i) {
          // New character needed.
          auto *new_box = new BoxChar("\t", 1);
          new_box->AddBox(x, y, width, height);
          new_box->page_ = (*boxes)[i]->page_;
          boxes->insert(boxes->begin() + i, new_box);
          ++i;
        } else {
          (*boxes)[i - 1]->AddBox(x, y, width, height);
          (*boxes)[i - 1]->ch_ = "\t";
        }
        max_shift = 0;
      } else if (shift > max_shift) {
        max_shift = shift;
      }
    }
    prev_i = i;
  }
}