static void GetWordBaseline(int writing_direction, int ppi, int height, int word_x1, int word_y1,
                            int word_x2, int word_y2, int line_x1, int line_y1, int line_x2,
                            int line_y2, double *x0, double *y0, double *length) {
  if (writing_direction == WRITING_DIRECTION_RIGHT_TO_LEFT) {
    std::swap(word_x1, word_x2);
    std::swap(word_y1, word_y2);
  }
  double word_length;
  double x, y;
  {
    int px = word_x1;
    int py = word_y1;
    double l2 = dist2(line_x1, line_y1, line_x2, line_y2);
    if (l2 == 0) {
      x = line_x1;
      y = line_y1;
    } else {
      double t = ((px - line_x2) * (line_x2 - line_x1) + (py - line_y2) * (line_y2 - line_y1)) / l2;
      x = line_x2 + t * (line_x2 - line_x1);
      y = line_y2 + t * (line_y2 - line_y1);
    }
    word_length = sqrt(static_cast<double>(dist2(word_x1, word_y1, word_x2, word_y2)));
    word_length = word_length * 72.0 / ppi;
    x = x * 72 / ppi;
    y = height - (y * 72.0 / ppi);
  }
  *x0 = x;
  *y0 = y;
  *length = word_length;
}