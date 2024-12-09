int TextlineProjection::VerticalDistance(bool debug, int x, int y1, int y2) const {
  x = ImageXToProjectionX(x);
  y1 = ImageYToProjectionY(y1);
  y2 = ImageYToProjectionY(y2);
  if (y1 == y2) {
    return 0;
  }
  int wpl = pixGetWpl(pix_);
  int step = y1 < y2 ? 1 : -1;
  uint32_t *data = pixGetData(pix_) + y1 * wpl;
  wpl *= step;
  int prev_pixel = GET_DATA_BYTE(data, x);
  int distance = 0;
  int right_way_steps = 0;
  for (int y = y1; y != y2; y += step) {
    data += wpl;
    int pixel = GET_DATA_BYTE(data, x);
    if (debug) {
      tprintf("At (%d,%d), pix = %d, prev=%d\n", x, y + step, pixel, prev_pixel);
    }
    if (pixel < prev_pixel) {
      distance += kWrongWayPenalty;
    } else if (pixel > prev_pixel) {
      ++right_way_steps;
    } else {
      ++distance;
    }
    prev_pixel = pixel;
  }
  return distance * scale_factor_ + right_way_steps * scale_factor_ / kWrongWayPenalty;
}