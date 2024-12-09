int TextlineProjection::HorizontalDistance(bool debug, int x1, int x2, int y) const {
  x1 = ImageXToProjectionX(x1);
  x2 = ImageXToProjectionX(x2);
  y = ImageYToProjectionY(y);
  if (x1 == x2) {
    return 0;
  }
  int wpl = pixGetWpl(pix_);
  int step = x1 < x2 ? 1 : -1;
  uint32_t *data = pixGetData(pix_) + y * wpl;
  int prev_pixel = GET_DATA_BYTE(data, x1);
  int distance = 0;
  int right_way_steps = 0;
  for (int x = x1; x != x2; x += step) {
    int pixel = GET_DATA_BYTE(data, x + step);
    if (debug) {
      tprintf("At (%d,%d), pix = %d, prev=%d\n", x + step, y, pixel, prev_pixel);
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