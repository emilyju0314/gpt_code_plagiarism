double QSPLINE::step( // find step functions
    double x1,        // between coords
    double x2) {
  int index1, index2; // indices of coords
  double total;       /*total steps */

  index1 = spline_index(x1);
  index2 = spline_index(x2);
  total = 0;
  while (index1 < index2) {
    total += static_cast<double>(quadratics[index1 + 1].y(static_cast<float>(xcoords[index1 + 1])));
    total -= static_cast<double>(quadratics[index1].y(static_cast<float>(xcoords[index1 + 1])));
    index1++; /*next segment */
  }
  return total; /*total steps */
}