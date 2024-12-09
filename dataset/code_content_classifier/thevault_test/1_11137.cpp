bool C_OUTLINE::IsLegallyNested() const {
  if (stepcount == 0) {
    return true;
  }
  int64_t parent_area = outer_area();
  // We aren't going to modify the list, or its contents, but there is
  // no const iterator.
  C_OUTLINE_IT child_it(const_cast<C_OUTLINE_LIST *>(&children));
  for (child_it.mark_cycle_pt(); !child_it.cycled_list(); child_it.forward()) {
    const C_OUTLINE *child = child_it.data();
    if (child->outer_area() * parent_area > 0 || !child->IsLegallyNested()) {
      return false;
    }
  }
  return true;
}