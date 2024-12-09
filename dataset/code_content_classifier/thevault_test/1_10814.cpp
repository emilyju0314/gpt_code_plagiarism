TBOX WERD::restricted_bounding_box(bool upper_dots, bool lower_dots) const {
  TBOX box = true_bounding_box();
  int bottom = box.bottom();
  int top = box.top();
  // This is a read-only iteration of the rejected blobs.
  C_BLOB_IT it(const_cast<C_BLOB_LIST *>(&rej_cblobs));
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    TBOX dot_box = it.data()->bounding_box();
    if ((upper_dots || dot_box.bottom() <= top) && (lower_dots || dot_box.top() >= bottom)) {
      box += dot_box;
    }
  }
  return box;
}