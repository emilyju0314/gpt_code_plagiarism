int TextlineProjection::MeanPixelsInLineSegment(const DENORM *denorm, int offset, TPOINT start_pt,
                                                TPOINT end_pt) const {
  TransformToPixCoords(denorm, &start_pt);
  TransformToPixCoords(denorm, &end_pt);
  TruncateToImageBounds(&start_pt);
  TruncateToImageBounds(&end_pt);
  int wpl = pixGetWpl(pix_);
  uint32_t *data = pixGetData(pix_);
  int total = 0;
  int count = 0;
  int x_delta = end_pt.x - start_pt.x;
  int y_delta = end_pt.y - start_pt.y;
  if (abs(x_delta) >= abs(y_delta)) {
    if (x_delta == 0) {
      return 0;
    }
    // Horizontal line. Add the offset vertically.
    int x_step = x_delta > 0 ? 1 : -1;
    // Correct offset for rotation, keeping it anti-clockwise of the delta.
    offset *= x_step;
    start_pt.y += offset;
    end_pt.y += offset;
    TruncateToImageBounds(&start_pt);
    TruncateToImageBounds(&end_pt);
    x_delta = end_pt.x - start_pt.x;
    y_delta = end_pt.y - start_pt.y;
    count = x_delta * x_step + 1;
    for (int x = start_pt.x; x != end_pt.x; x += x_step) {
      int y = start_pt.y + DivRounded(y_delta * (x - start_pt.x), x_delta);
      total += GET_DATA_BYTE(data + wpl * y, x);
    }
  } else {
    // Vertical line. Add the offset horizontally.
    int y_step = y_delta > 0 ? 1 : -1;
    // Correct offset for rotation, keeping it anti-clockwise of the delta.
    // Pix holds the image with y=0 at the top, so the offset is negated.
    offset *= -y_step;
    start_pt.x += offset;
    end_pt.x += offset;
    TruncateToImageBounds(&start_pt);
    TruncateToImageBounds(&end_pt);
    x_delta = end_pt.x - start_pt.x;
    y_delta = end_pt.y - start_pt.y;
    count = y_delta * y_step + 1;
    for (int y = start_pt.y; y != end_pt.y; y += y_step) {
      int x = start_pt.x + DivRounded(x_delta * (y - start_pt.y), y_delta);
      total += GET_DATA_BYTE(data + wpl * y, x);
    }
  }
  return DivRounded(total, count);
}