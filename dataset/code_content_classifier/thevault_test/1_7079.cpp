static int clip_x (int x) {

  int kmin = -fl_line_width_;
  int kmax = SHRT_MAX - fl_line_width_;

  if (x < kmin)
    x = kmin;
  else if (x > kmax)
    x = kmax;
  return x;
}