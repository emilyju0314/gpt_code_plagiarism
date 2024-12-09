void PSView::string(float fx, float fy, float dim, const char* s, int anchor, 
		    const char*)
{
  float x, y;
  matrix_.map(fx, fy, x, y);

  float dummy, dlow, dhigh;
  matrix_.map(0., 0., dummy, dlow);
  matrix_.map(0., 0.6 * dim, dummy, dhigh);
  int d = int(dhigh - dlow);
  fprintf(file_, "%d ft\n", d);

  fprintf(file_, "0 0 0 setrgbcolor\n");
  switch (anchor) {
  case ANCHOR_CENTER:
    fprintf(file_, "%.1f %.1f (%s) center_show\n", x, y, s);
    break;
  case ANCHOR_NORTH:
    fprintf(file_, "%.1f %.1f (%s) north_show\n", x, y, s);
    break;
  case ANCHOR_SOUTH:
    fprintf(file_, "%.1f %.1f (%s) south_show\n", x, y, s);
    break;
  case ANCHOR_WEST:
    fprintf(file_, "%.1f %.1f (%s) west_show\n", x, y, s);
    break;
  case ANCHOR_EAST:
    fprintf(file_, "%.1f %.1f (%s) east_show\n", x, y, s);
    break;
  }
}