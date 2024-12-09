void BoxWord::ClipToOriginalWord(const BLOCK *block, WERD *original_word) {
  for (unsigned i = 0; i < length_; ++i) {
    TBOX box = boxes_[i];
    // Expand by a single pixel, as the poly approximation error is 1 pixel.
    box =
        TBOX(box.left() - 1, box.bottom() - 1, box.right() + 1, box.top() + 1);
    // Now find the original box that matches.
    TBOX original_box;
    C_BLOB_IT b_it(original_word->cblob_list());
    for (b_it.mark_cycle_pt(); !b_it.cycled_list(); b_it.forward()) {
      TBOX blob_box = b_it.data()->bounding_box();
      if (block != nullptr) {
        blob_box.rotate(block->re_rotation());
      }
      if (blob_box.major_overlap(box)) {
        original_box += blob_box;
      }
    }
    if (!original_box.null_box()) {
      if (NearlyEqual<int>(original_box.left(), box.left(),
                           kBoxClipTolerance)) {
        box.set_left(original_box.left());
      }
      if (NearlyEqual<int>(original_box.right(), box.right(),
                           kBoxClipTolerance)) {
        box.set_right(original_box.right());
      }
      if (NearlyEqual<int>(original_box.top(), box.top(), kBoxClipTolerance)) {
        box.set_top(original_box.top());
      }
      if (NearlyEqual<int>(original_box.bottom(), box.bottom(),
                           kBoxClipTolerance)) {
        box.set_bottom(original_box.bottom());
      }
    }
    original_box = original_word->bounding_box();
    if (block != nullptr) {
      original_box.rotate(block->re_rotation());
    }
    boxes_[i] = box.intersection(original_box);
  }
  ComputeBoundingBox();
}