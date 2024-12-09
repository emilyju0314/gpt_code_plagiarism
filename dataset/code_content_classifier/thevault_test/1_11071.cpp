bool PDBLK::contains( // test containment
    ICOORD pt         // point to test
) {
  BLOCK_RECT_IT it = this; // rectangle iterator
  ICOORD bleft, tright;    // corners of rectangle

  for (it.start_block(); !it.cycled_rects(); it.forward()) {
    // get rectangle
    it.bounding_box(bleft, tright);
    // inside rect
    if (pt.x() >= bleft.x() && pt.x() <= tright.x() && pt.y() >= bleft.y() &&
        pt.y() <= tright.y()) {
      return true; // is inside
    }
  }
  return false; // not inside
}