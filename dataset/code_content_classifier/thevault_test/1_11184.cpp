int16_t POLY_BLOCK::winding_number(const ICOORD &point) {
  int16_t count;               // winding count
  ICOORD pt;                   // current point
  ICOORD vec;                  // point to current point
  ICOORD vvec;                 // current point to next point
  int32_t cross;               // cross product
  ICOORDELT_IT it = &vertices; // iterator

  count = 0;
  do {
    pt = *it.data();
    vec = pt - point;
    vvec = *it.data_relative(1) - pt;
    // crossing the line
    if (vec.y() <= 0 && vec.y() + vvec.y() > 0) {
      cross = vec * vvec; // cross product
      if (cross > 0) {
        count++; // crossing right half
      } else if (cross == 0) {
        return INTERSECTING; // going through point
      }
    } else if (vec.y() > 0 && vec.y() + vvec.y() <= 0) {
      cross = vec * vvec;
      if (cross < 0) {
        count--; // crossing back
      } else if (cross == 0) {
        return INTERSECTING; // illegal
      }
    } else if (vec.y() == 0 && vec.x() == 0) {
      return INTERSECTING;
    }
    it.forward();
  } while (!it.at_first());
  return count; // winding number
}