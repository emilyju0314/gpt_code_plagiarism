TBOX ROW::restricted_bounding_box(bool upper_dots, bool lower_dots) const {
  TBOX box;
  // This is a read-only iteration of the words in the row.
  WERD_IT it(const_cast<WERD_LIST *>(&words));
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    box += it.data()->restricted_bounding_box(upper_dots, lower_dots);
  }
  return box;
}