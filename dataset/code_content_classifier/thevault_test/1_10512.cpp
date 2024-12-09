static void AffineMatrix(int writing_direction, int line_x1, int line_y1, int line_x2, int line_y2,
                         double *a, double *b, double *c, double *d) {
  double theta =
      atan2(static_cast<double>(line_y1 - line_y2), static_cast<double>(line_x2 - line_x1));
  *a = cos(theta);
  *b = sin(theta);
  *c = -sin(theta);
  *d = cos(theta);
  switch (writing_direction) {
    case WRITING_DIRECTION_RIGHT_TO_LEFT:
      *a = -*a;
      *b = -*b;
      break;
    case WRITING_DIRECTION_TOP_TO_BOTTOM:
      // TODO(jbreiden) Consider using the vertical PDF writing mode.
      break;
    default:
      break;
  }
}