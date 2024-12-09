void WERD::CleanNoise(float size_threshold) {
  C_BLOB_IT blob_it(&cblobs);
  C_BLOB_IT rej_it(&rej_cblobs);
  for (blob_it.mark_cycle_pt(); !blob_it.cycled_list(); blob_it.forward()) {
    C_BLOB *blob = blob_it.data();
    C_OUTLINE_IT ol_it(blob->out_list());
    for (ol_it.mark_cycle_pt(); !ol_it.cycled_list(); ol_it.forward()) {
      C_OUTLINE *outline = ol_it.data();
      TBOX ol_box = outline->bounding_box();
      int ol_size = ol_box.width() > ol_box.height() ? ol_box.width() : ol_box.height();
      if (ol_size < size_threshold) {
        // This outline is too small. Move it to a separate blob in the
        // reject blobs list.
        auto *rej_blob = new C_BLOB(ol_it.extract());
        rej_it.add_after_then_move(rej_blob);
      }
    }
    if (blob->out_list()->empty()) {
      delete blob_it.extract();
    }
  }
}