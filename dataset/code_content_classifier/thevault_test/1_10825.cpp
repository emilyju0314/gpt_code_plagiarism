bool WERD::AddSelectedOutlines(const std::vector<bool> &wanted,
                               const std::vector<C_BLOB *> &target_blobs,
                               const std::vector<C_OUTLINE *> &outlines,
                               bool *make_next_word_fuzzy) {
  bool outline_added_to_start = false;
  if (make_next_word_fuzzy != nullptr) {
    *make_next_word_fuzzy = false;
  }
  C_BLOB_IT rej_it(&rej_cblobs);
  for (unsigned i = 0; i < outlines.size(); ++i) {
    C_OUTLINE *outline = outlines[i];
    if (outline == nullptr) {
      continue; // Already used it.
    }
    if (wanted[i]) {
      C_BLOB *target_blob = target_blobs[i];
      TBOX noise_box = outline->bounding_box();
      if (target_blob == nullptr) {
        target_blob = new C_BLOB(outline);
        // Need to find the insertion point.
        C_BLOB_IT blob_it(&cblobs);
        for (blob_it.mark_cycle_pt(); !blob_it.cycled_list(); blob_it.forward()) {
          C_BLOB *blob = blob_it.data();
          TBOX blob_box = blob->bounding_box();
          if (blob_box.left() > noise_box.left()) {
            if (blob_it.at_first() && !flag(W_FUZZY_SP) && !flag(W_FUZZY_NON)) {
              // We might want to join this word to its predecessor.
              outline_added_to_start = true;
            }
            blob_it.add_before_stay_put(target_blob);
            break;
          }
        }
        if (blob_it.cycled_list()) {
          blob_it.add_to_end(target_blob);
          if (make_next_word_fuzzy != nullptr) {
            *make_next_word_fuzzy = true;
          }
        }
        // Add all consecutive wanted, but null-blob outlines to same blob.
        C_OUTLINE_IT ol_it(target_blob->out_list());
        while (i + 1 < outlines.size() && wanted[i + 1] && target_blobs[i + 1] == nullptr) {
          ++i;
          ol_it.add_to_end(outlines[i]);
        }
      } else {
        // Insert outline into this blob.
        C_OUTLINE_IT ol_it(target_blob->out_list());
        ol_it.add_to_end(outline);
      }
    } else {
      // Put back on noise list.
      rej_it.add_to_end(new C_BLOB(outline));
    }
  }
  return outline_added_to_start;
}