float DistanceSquared(int k, PARAM_DESC *dim, float p1[], float p2[]) {
  float total_distance = 0;

  for (; k > 0; k--, p1++, p2++, dim++) {
    if (dim->NonEssential) {
      continue;
    }

    float dimension_distance = *p1 - *p2;

    /* if this dimension is circular - check wraparound distance */
    if (dim->Circular) {
      dimension_distance = Magnitude(dimension_distance);
      float wrap_distance = dim->Max - dim->Min - dimension_distance;
      dimension_distance = std::min(dimension_distance, wrap_distance);
    }

    total_distance += dimension_distance * dimension_distance;
  }
  return total_distance;
}