TBOX WERD::true_bounding_box() const {
  TBOX box; // box being built
  // This is a read-only iteration of the good blobs.
  C_BLOB_IT it(const_cast<C_BLOB_LIST *>(&cblobs));
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    box += it.data()->bounding_box();
  }
  return box;
}