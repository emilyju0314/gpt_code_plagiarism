static void ClipBaseline(int ppi, int x1, int y1, int x2, int y2, int *line_x1, int *line_y1,
                         int *line_x2, int *line_y2) {
  *line_x1 = x1;
  *line_y1 = y1;
  *line_x2 = x2;
  *line_y2 = y2;
  int rise = abs(y2 - y1) * 72;
  int run = abs(x2 - x1) * 72;
  if (rise < 2 * ppi && 2 * ppi < run) {
    *line_y1 = *line_y2 = (y1 + y2) / 2;
  }
}