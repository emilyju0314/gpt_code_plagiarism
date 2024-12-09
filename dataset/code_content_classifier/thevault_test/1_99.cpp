int safeCast(float x, float missingIn, int missingOut) {
  if (x == missingIn)
    return missingOut;
  // Throws boost::math::rounding_error if x is outside the range representable by ints
  return boost::math::iround(x);
}