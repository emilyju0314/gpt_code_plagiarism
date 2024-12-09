void Tesseract::flip_hyphens(WERD_RES *word_res) {
  WERD_CHOICE *best_choice = word_res->best_choice;
  int prev_right = -9999;
  int next_left;
  TBOX out_box;
  float aspect_ratio;

  if (tessedit_lower_flip_hyphen <= 1) {
    return;
  }

  auto num_blobs = word_res->rebuild_word->NumBlobs();
  UNICHAR_ID unichar_dash = word_res->uch_set->unichar_to_id("-");
  for (unsigned i = 0; i < best_choice->length() && i < num_blobs; ++i) {
    TBLOB *blob = word_res->rebuild_word->blobs[i];
    out_box = blob->bounding_box();
    if (i + 1 == num_blobs) {
      next_left = 9999;
    } else {
      next_left = word_res->rebuild_word->blobs[i + 1]->bounding_box().left();
    }
    // Don't touch small or touching blobs - it is too dangerous.
    if ((out_box.width() > 8 * word_res->denorm.x_scale()) && (out_box.left() > prev_right) &&
        (out_box.right() < next_left)) {
      aspect_ratio = out_box.width() / static_cast<float>(out_box.height());
      if (word_res->uch_set->eq(best_choice->unichar_id(i), ".")) {
        if (aspect_ratio >= tessedit_upper_flip_hyphen &&
            word_res->uch_set->contains_unichar_id(unichar_dash) &&
            word_res->uch_set->get_enabled(unichar_dash)) {
          /* Certain HYPHEN */
          best_choice->set_unichar_id(unichar_dash, i);
          if (word_res->reject_map[i].rejected()) {
            word_res->reject_map[i].setrej_hyphen_accept();
          }
        }
        if ((aspect_ratio > tessedit_lower_flip_hyphen) && word_res->reject_map[i].accepted()) {
          // Suspected HYPHEN
          word_res->reject_map[i].setrej_hyphen();
        }
      } else if (best_choice->unichar_id(i) == unichar_dash) {
        if ((aspect_ratio >= tessedit_upper_flip_hyphen) && (word_res->reject_map[i].rejected())) {
          word_res->reject_map[i].setrej_hyphen_accept();
        }
        // Certain HYPHEN

        if ((aspect_ratio <= tessedit_lower_flip_hyphen) && (word_res->reject_map[i].accepted())) {
          // Suspected HYPHEN
          word_res->reject_map[i].setrej_hyphen();
        }
      }
    }
    prev_right = out_box.right();
  }
}