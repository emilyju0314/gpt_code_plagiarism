static void RotateOutlineList(const FCOORD &rotation, C_OUTLINE_LIST *outlines) {
  C_OUTLINE_LIST new_outlines;
  C_OUTLINE_IT src_it(outlines);
  C_OUTLINE_IT dest_it(&new_outlines);
  while (!src_it.empty()) {
    C_OUTLINE *old_outline = src_it.extract();
    src_it.forward();
    auto *new_outline = new C_OUTLINE(old_outline, rotation);
    if (!old_outline->child()->empty()) {
      RotateOutlineList(rotation, old_outline->child());
      C_OUTLINE_IT child_it(new_outline->child());
      child_it.add_list_after(old_outline->child());
    }
    delete old_outline;
    dest_it.add_to_end(new_outline);
  }
  src_it.add_list_after(&new_outlines);
}