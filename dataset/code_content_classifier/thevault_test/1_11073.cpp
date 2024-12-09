void BLOCK_RECT_IT::forward() { // next rectangle
  if (!left_it.empty()) {       // non-empty list
    if (left_it.data_relative(1)->y() == ymax) {
      left_it.forward(); // move to meet top
    }
    if (right_it.data_relative(1)->y() == ymax) {
      right_it.forward();
    }
    // last is special
    if (left_it.at_last() || right_it.at_last()) {
      left_it.move_to_first(); // restart
      right_it.move_to_first();
      // now at bottom
      ymin = left_it.data()->y();
    } else {
      ymin = ymax; // new bottom
    }
    // next point
    ymax = left_it.data_relative(1)->y();
    if (right_it.data_relative(1)->y() < ymax) {
      // least step forward
      ymax = right_it.data_relative(1)->y();
    }
  }
}