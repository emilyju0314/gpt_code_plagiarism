int32_t C_OUTLINE::perimeter() const {
  int32_t total_steps; // Return value.
  // We aren't going to modify the list, or its contents, but there is
  // no const iterator.
  C_OUTLINE_IT it(const_cast<C_OUTLINE_LIST *>(&children));

  total_steps = pathlength();
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    total_steps += it.data()->pathlength(); // Add perimeters of children.
  }

  return total_steps;
}