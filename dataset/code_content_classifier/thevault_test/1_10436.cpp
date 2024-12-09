TBOX C_BLOB::bounding_box() const { // bounding box
  // This is a read-only iteration of the outlines.
  C_OUTLINE_IT it = const_cast<C_OUTLINE_LIST *>(&outlines);
  TBOX box; // bounding box

  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    C_OUTLINE *outline = it.data();
    box += outline->bounding_box();
  }
  return box;
}