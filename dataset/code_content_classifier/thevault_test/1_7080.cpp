Fl_Region XRectangleRegion(int x, int y, int w, int h) {
  XRectangle R;
  clip_to_short(x, y, w, h);
  R.x = x; R.y = y; R.width = w; R.height = h;
  Fl_Region r = XCreateRegion();
  XUnionRectWithRegion(&R, r, r);
  return r;
}