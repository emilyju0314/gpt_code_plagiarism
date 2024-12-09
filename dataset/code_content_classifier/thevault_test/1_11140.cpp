void C_OUTLINE::ComputeEdgeOffsets(int threshold, Image pix) {
  if (pixGetDepth(pix) != 8) {
    return;
  }
  const l_uint32 *data = pixGetData(pix);
  int wpl = pixGetWpl(pix);
  int width = pixGetWidth(pix);
  int height = pixGetHeight(pix);
  bool negative = flag(COUT_INVERSE);
  delete[] offsets;
  offsets = new EdgeOffset[stepcount];
  ICOORD pos = start;
  ICOORD prev_gradient;
  ComputeGradient(data, wpl, pos.x(), height - pos.y(), width, height, &prev_gradient);
  for (int s = 0; s < stepcount; ++s) {
    ICOORD step_vec = step(s);
    TPOINT pt1(pos);
    pos += step_vec;
    TPOINT pt2(pos);
    ICOORD next_gradient;
    ComputeGradient(data, wpl, pos.x(), height - pos.y(), width, height, &next_gradient);
    // Use the sum of the prev and next as the working gradient.
    ICOORD gradient = prev_gradient + next_gradient;
    // best_diff will be manipulated to be always positive.
    int best_diff = 0;
    // offset will be the extrapolation of the location of the greyscale
    // threshold from the edge with the largest difference, relative to the
    // location of the binary edge.
    int offset = 0;
    if (pt1.y == pt2.y && abs(gradient.y()) * 2 >= abs(gradient.x())) {
      // Horizontal step. diff_sign == 1 indicates black above.
      int diff_sign = (pt1.x > pt2.x) == negative ? 1 : -1;
      int x = std::min(pt1.x, pt2.x);
      int y = height - pt1.y;
      int best_sum = 0;
      int best_y = y;
      EvaluateVerticalDiff(data, wpl, diff_sign, x, y, height, &best_diff, &best_sum, &best_y);
      // Find the strongest edge.
      int test_y = y;
      do {
        ++test_y;
      } while (EvaluateVerticalDiff(data, wpl, diff_sign, x, test_y, height, &best_diff, &best_sum,
                                    &best_y));
      test_y = y;
      do {
        --test_y;
      } while (EvaluateVerticalDiff(data, wpl, diff_sign, x, test_y, height, &best_diff, &best_sum,
                                    &best_y));
      offset = diff_sign * (best_sum / 2 - threshold) + (y - best_y) * best_diff;
    } else if (pt1.x == pt2.x && abs(gradient.x()) * 2 >= abs(gradient.y())) {
      // Vertical step. diff_sign == 1 indicates black on the left.
      int diff_sign = (pt1.y > pt2.y) == negative ? 1 : -1;
      int x = pt1.x;
      int y = height - std::max(pt1.y, pt2.y);
      const l_uint32 *line = pixGetData(pix) + y * wpl;
      int best_sum = 0;
      int best_x = x;
      EvaluateHorizontalDiff(line, diff_sign, x, width, &best_diff, &best_sum, &best_x);
      // Find the strongest edge.
      int test_x = x;
      do {
        ++test_x;
      } while (
          EvaluateHorizontalDiff(line, diff_sign, test_x, width, &best_diff, &best_sum, &best_x));
      test_x = x;
      do {
        --test_x;
      } while (
          EvaluateHorizontalDiff(line, diff_sign, test_x, width, &best_diff, &best_sum, &best_x));
      offset = diff_sign * (threshold - best_sum / 2) + (best_x - x) * best_diff;
    }
    offsets[s].offset_numerator = ClipToRange<int>(offset, -INT8_MAX, INT8_MAX);
    offsets[s].pixel_diff = ClipToRange<int>(best_diff, 0, UINT8_MAX);
    if (negative) {
      gradient = -gradient;
    }
    // Compute gradient angle quantized to 256 directions, rotated by 64 (pi/2)
    // to convert from gradient direction to edge direction.
    offsets[s].direction = Modulo(FCOORD::binary_angle_plus_pi(gradient.angle()) + 64, 256);
    prev_gradient = next_gradient;
  }
}