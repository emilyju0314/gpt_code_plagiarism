void Fl::screen_xywh(int &X, int &Y, int &W, int &H, int mx, int my) {
  if (!num_screens) screen_init();

#ifdef WIN32
  if (num_screens > 1) {
    int i;

    for (i = 0; i < num_screens; i ++) {
      if (mx >= screens[i].left && mx < screens[i].right &&
	  my >= screens[i].top && my < screens[i].bottom) {
	X = screens[i].left;
	Y = screens[i].top;
	W = screens[i].right - screens[i].left;
	H = screens[i].bottom - screens[i].top;
	return;
      }
    }
  }
#elif defined(__APPLE__)
  if (num_screens > 1) {
    int i;

    for (i = 0; i < num_screens; i ++) {
      if (mx >= screens[i].x &&
	  mx < (screens[i].x + screens[i].width) &&
	  my >= screens[i].y &&
	  my < (screens[i].y + screens[i].height)) {
	X = screens[i].x;
	Y = screens[i].y;
	W = screens[i].width;
	H = screens[i].height;
	return;
      }
    }
  }
#elif HAVE_XINERAMA
  if (num_screens > 1) {
    int i;

    for (i = 0; i < num_screens; i ++) {
      if (mx >= screens[i].x_org &&
	  mx < (screens[i].x_org + screens[i].width) &&
	  my >= screens[i].y_org &&
	  my < (screens[i].y_org + screens[i].height)) {
	X = screens[i].x_org;
	Y = screens[i].y_org;
	W = screens[i].width;
	H = screens[i].height;
	return;
      }
    }
  }
#else
  (void)mx;
  (void)my;
#endif // WIN32

  X = Fl::x();
  Y = Fl::y();
  W = Fl::w();
  H = Fl::h();
}