TDimension BLOCK_LINE_IT::get_line( // get a line
    TDimension y,                   // line to get
    TDimension &xext                // output extent
) {
  ICOORD bleft;  // bounding box
  ICOORD tright; // of block & rect

  // get block box
  block->bounding_box(bleft, tright);
  if (y < bleft.y() || y >= tright.y()) {
    //              block->print(stderr,false);
    BADBLOCKLINE.error("BLOCK_LINE_IT::get_line", ABORT, "Y=%d", y);
  }

  // get rectangle box
  rect_it.bounding_box(bleft, tright);
  // inside rectangle
  if (y >= bleft.y() && y < tright.y()) {
    // width of line
    xext = tright.x() - bleft.x();
    return bleft.x(); // start of line
  }
  for (rect_it.start_block(); !rect_it.cycled_rects(); rect_it.forward()) {
    // get rectangle box
    rect_it.bounding_box(bleft, tright);
    // inside rectangle
    if (y >= bleft.y() && y < tright.y()) {
      // width of line
      xext = tright.x() - bleft.x();
      return bleft.x(); // start of line
    }
  }
  LOSTBLOCKLINE.error("BLOCK_LINE_IT::get_line", ABORT, "Y=%d", y);
  return 0; // dummy to stop warning
}