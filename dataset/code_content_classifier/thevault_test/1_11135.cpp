int16_t C_OUTLINE::winding_number(ICOORD point) const {
  int16_t stepindex; // index to cstep
  int16_t count;     // winding count
  ICOORD vec;        // to current point
  ICOORD stepvec;    // step vector
  int32_t cross;     // cross product

  vec = start - point; // vector to it
  count = 0;
  for (stepindex = 0; stepindex < stepcount; stepindex++) {
    stepvec = step(stepindex); // get the step
                               // crossing the line
    if (vec.y() <= 0 && vec.y() + stepvec.y() > 0) {
      cross = vec * stepvec; // cross product
      if (cross > 0) {
        count++; // crossing right half
      } else if (cross == 0) {
        return INTERSECTING; // going through point
      }
    } else if (vec.y() > 0 && vec.y() + stepvec.y() <= 0) {
      cross = vec * stepvec;
      if (cross < 0) {
        count--; // crossing back
      } else if (cross == 0) {
        return INTERSECTING; // illegal
      }
    }
    vec += stepvec; // sum vectors
  }
  return count; // winding number
}