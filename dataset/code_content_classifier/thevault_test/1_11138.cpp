void C_OUTLINE::RemoveSmallRecursive(int min_size, C_OUTLINE_IT *it) {
  if (box.width() < min_size || box.height() < min_size) {
    ASSERT_HOST(this == it->data());
    delete it->extract(); // Too small so get rid of it and any children.
  } else if (!children.empty()) {
    // Search the children of this, deleting any that are too small.
    C_OUTLINE_IT child_it(&children);
    for (child_it.mark_cycle_pt(); !child_it.cycled_list(); child_it.forward()) {
      C_OUTLINE *child = child_it.data();
      child->RemoveSmallRecursive(min_size, &child_it);
    }
  }
}