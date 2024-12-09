bool KDTreeSearch::BoxIntersectsSearch(float *lower, float *upper) {
  float *query = query_point_;
  // Compute the sum in higher precision.
  double total_distance = 0.0;
  double radius_squared =
      static_cast<double>(results_.max_insertable_key()) * results_.max_insertable_key();
  PARAM_DESC *dim = &tree_->KeyDesc[0];

  for (int i = tree_->KeySize; i > 0; i--, dim++, query++, lower++, upper++) {
    if (dim->NonEssential) {
      continue;
    }

    float dimension_distance;
    if (*query < *lower) {
      dimension_distance = *lower - *query;
    } else if (*query > *upper) {
      dimension_distance = *query - *upper;
    } else {
      dimension_distance = 0;
    }

    /* if this dimension is circular - check wraparound distance */
    if (dim->Circular) {
      float wrap_distance = FLT_MAX;
      if (*query < *lower) {
        wrap_distance = *query + dim->Max - dim->Min - *upper;
      } else if (*query > *upper) {
        wrap_distance = *lower - (*query - (dim->Max - dim->Min));
      }
      dimension_distance = std::min(dimension_distance, wrap_distance);
    }

    total_distance += static_cast<double>(dimension_distance) * dimension_distance;
    if (total_distance >= radius_squared) {
      return false;
    }
  }
  return true;
}