void PDBLK::set_sides(    // set vertex lists
    ICOORDELT_LIST *left, // left vertices
    ICOORDELT_LIST *right // right vertices
) {
  // boundaries
  ICOORDELT_IT left_it = &leftside;
  ICOORDELT_IT right_it = &rightside;

  leftside.clear();
  left_it.move_to_first();
  left_it.add_list_before(left);
  rightside.clear();
  right_it.move_to_first();
  right_it.add_list_before(right);
}