double ImageFind::ColorDistanceFromLine(const uint8_t *line1, const uint8_t *line2,
                                        const uint8_t *point) {
  int line_vector[kRGBRMSColors];
  int point_vector[kRGBRMSColors];
  for (int i = 0; i < kRGBRMSColors; ++i) {
    line_vector[i] = static_cast<int>(line2[i]) - static_cast<int>(line1[i]);
    point_vector[i] = static_cast<int>(point[i]) - static_cast<int>(line1[i]);
  }
  line_vector[L_ALPHA_CHANNEL] = 0;
  // Now the cross product in 3d.
  int cross[kRGBRMSColors];
  cross[COLOR_RED] = line_vector[COLOR_GREEN] * point_vector[COLOR_BLUE] -
                     line_vector[COLOR_BLUE] * point_vector[COLOR_GREEN];
  cross[COLOR_GREEN] = line_vector[COLOR_BLUE] * point_vector[COLOR_RED] -
                       line_vector[COLOR_RED] * point_vector[COLOR_BLUE];
  cross[COLOR_BLUE] = line_vector[COLOR_RED] * point_vector[COLOR_GREEN] -
                      line_vector[COLOR_GREEN] * point_vector[COLOR_RED];
  cross[L_ALPHA_CHANNEL] = 0;
  // Now the sums of the squares.
  double cross_sq = 0.0;
  double line_sq = 0.0;
  for (int j = 0; j < kRGBRMSColors; ++j) {
    cross_sq += static_cast<double>(cross[j]) * cross[j];
    line_sq += static_cast<double>(line_vector[j]) * line_vector[j];
  }
  if (line_sq == 0.0) {
    return 0.0;
  }
  return cross_sq / line_sq; // This is the squared distance.
}