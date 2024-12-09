void ICOORD::set_with_shrink(int x, int y) {
  // Fit the vector into an ICOORD, which is 16 bit.
  int factor = 1;
  int max_extent = std::max(abs(x), abs(y));
  if (max_extent > INT16_MAX) {
    factor = max_extent / INT16_MAX + 1;
  }
  xcoord = x / factor;
  ycoord = y / factor;
}