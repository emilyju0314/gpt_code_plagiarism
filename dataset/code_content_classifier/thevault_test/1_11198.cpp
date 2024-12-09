static void MergeBoxCharsToWords(std::vector<BoxChar *> *boxchars) {
  std::vector<BoxChar *> result;
  bool started_word = false;
  for (auto &boxchar : *boxchars) {
    if (boxchar->ch() == " " || boxchar->box() == nullptr) {
      result.push_back(boxchar);
      boxchar = nullptr;
      started_word = false;
      continue;
    }

    if (!started_word) {
      // Begin new word
      started_word = true;
      result.push_back(boxchar);
      boxchar = nullptr;
    } else {
      BoxChar *last_boxchar = result.back();
      // Compute bounding box union
      const Box *box = boxchar->box();
      Box *last_box = last_boxchar->mutable_box();
      int left = std::min(last_box->x, box->x);
      int right = std::max(last_box->x + last_box->w, box->x + box->w);
      int top = std::min(last_box->y, box->y);
      int bottom = std::max(last_box->y + last_box->h, box->y + box->h);
      // Conclude that the word was broken to span multiple lines based on the
      // size of the merged bounding box in relation to those of the individual
      // characters seen so far.
      if (right - left > last_box->w + 5 * box->w) {
        tlog(1, "Found line break after '%s'", last_boxchar->ch().c_str());
        // Insert a fake interword space and start a new word with the current
        // boxchar.
        result.push_back(new BoxChar(" ", 1));
        result.push_back(boxchar);
        boxchar = nullptr;
        continue;
      }
      // Append to last word
      last_boxchar->mutable_ch()->append(boxchar->ch());
      last_box->x = left;
      last_box->w = right - left;
      last_box->y = top;
      last_box->h = bottom - top;
      delete boxchar;
      boxchar = nullptr;
    }
  }
  boxchars->swap(result);
}