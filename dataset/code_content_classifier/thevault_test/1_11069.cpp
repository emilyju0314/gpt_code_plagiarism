PDBLK::PDBLK(                   // rectangular block
    TDimension xmin,            // bottom left
    TDimension ymin,
    TDimension xmax,            // top right
    TDimension ymax)
    : box(ICOORD(xmin, ymin), ICOORD(xmax, ymax)) {
  // boundaries
  ICOORDELT_IT left_it = &leftside;
  ICOORDELT_IT right_it = &rightside;

  hand_poly = nullptr;
  left_it.set_to_list(&leftside);
  right_it.set_to_list(&rightside);
  // make default box
  left_it.add_to_end(new ICOORDELT(xmin, ymin));
  left_it.add_to_end(new ICOORDELT(xmin, ymax));
  right_it.add_to_end(new ICOORDELT(xmax, ymin));
  right_it.add_to_end(new ICOORDELT(xmax, ymax));
  index_ = 0;
}