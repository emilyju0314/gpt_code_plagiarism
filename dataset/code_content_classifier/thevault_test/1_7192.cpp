int Fl_X::fake_X_wm(const Fl_Window* w,int &X,int &Y, int &bt,int &bx, int &by) {
  int W, H, xoff, yoff, dx, dy;
  int ret = bx = by = bt = 0;

  int fallback = 1;
  if (!w->parent()) {
    HWND hwnd = fl_xid(w);
    if (hwnd) {
      // The block below calculates the window borders by requesting the
      // required decorated window rectangle for a desired client rectangle.
      // If any part of the function above fails, we will drop to a 
      // fallback to get the best guess which is always available.
      HWND hwnd = fl_xid(w);
      // request the style flags of this window, as WIN32 sees them
      LONG style = GetWindowLong(hwnd, GWL_STYLE);
      LONG exstyle = GetWindowLong(hwnd, GWL_EXSTYLE);
      RECT r;
      r.left = w->x();
      r.top = w->y();
      r.right = w->x()+w->w();
      r.bottom = w->y()+w->h();
      // get the decoration rectangle for the desired client rectangle
      BOOL ok = AdjustWindowRectEx(&r, style, FALSE, exstyle);
      if (ok) {
        X = r.left;
        Y = r.top;
        W = r.right - r.left;
        H = r.bottom - r.top;
        bx = w->x() - r.left;
        by = r.bottom - w->y() - w->h(); // height of the bootm frame
        bt = w->y() - r.top - by; // height of top caption bar
        xoff = bx;
        yoff = by + bt;
        dx = W - w->w();
        dy = H - w->h();
        if (w->size_range_set && (w->maxw != w->minw || w->maxh != w->minh))
          ret = 2;
        else
          ret = 1;
        fallback = 0;
      }
    }
  }
  // This is the original (pre 1.1.7) routine to calculate window border sizes.
  if (fallback) {
    if (w->border() && !w->parent()) {
      if (w->size_range_set && (w->maxw != w->minw || w->maxh != w->minh)) {
        ret = 2;
        bx = GetSystemMetrics(SM_CXSIZEFRAME);
        by = GetSystemMetrics(SM_CYSIZEFRAME);
      } else {
        ret = 1;
        bx = GetSystemMetrics(SM_CXFIXEDFRAME);
        by = GetSystemMetrics(SM_CYFIXEDFRAME);
      }
      bt = GetSystemMetrics(SM_CYCAPTION);
    }
    //The coordinates of the whole window, including non-client area
    xoff = bx;
    yoff = by + bt;
    dx = 2*bx;
    dy = 2*by + bt;
    X = w->x()-xoff;
    Y = w->y()-yoff;
    W = w->w()+dx;
    H = w->h()+dy;
  }

  //Proceed to positioning the window fully inside the screen, if possible
  //Make border's lower right corner visible
  int scr_x, scr_y, scr_w, scr_h;
  Fl::screen_xywh(scr_x, scr_y, scr_w, scr_h, X, Y);
  if (scr_x+scr_w < X+W) X = scr_x+scr_w - W;
  if (scr_y+scr_h < Y+H) Y = scr_y+scr_h - H;
  //Make border's upper left corner visible
  if (X<scr_x) X = scr_x;
  if (Y<scr_y) Y = scr_y;
  //Make client area's lower right corner visible
  if (scr_x+scr_w < X+dx+ w->w()) X = scr_x+scr_w - w->w() - dx;
  if (scr_y+scr_h < Y+dy+ w->h()) Y = scr_y+scr_h - w->h() - dy;
  //Make client area's upper left corner visible
  if (X+xoff < scr_x) X = scr_x-xoff;
  if (Y+yoff < scr_y) Y = scr_y-yoff;
  //Return the client area's top left corner in (X,Y)
  X+=xoff;
  Y+=yoff;

  return ret;
}