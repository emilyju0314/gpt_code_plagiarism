void Fl_Scroll::recalc_scrollbars(ScrollInfo &si) {

  // inner box of widget (excluding scrollbars)
  si.innerbox_x = x()+Fl::box_dx(box());
  si.innerbox_y = y()+Fl::box_dy(box());
  si.innerbox_w = w()-Fl::box_dw(box());
  si.innerbox_h = h()-Fl::box_dh(box());

  // accumulate a bounding box for all the children
  si.child_l = si.innerbox_x;
  si.child_r = si.innerbox_x;
  si.child_b = si.innerbox_y;
  si.child_t = si.innerbox_y;
  int first = 1;
  Fl_Widget*const* a = array();
  for (int i=children()-2; i--;) {
    Fl_Widget* o = *a++;
    if ( first ) {
        first = 0;
	si.child_l = o->x();
	si.child_r = o->x()+o->w();
	si.child_b = o->y()+o->h();
	si.child_t = o->y();
    } else {
	if (o->x() < si.child_l) si.child_l = o->x();
	if (o->y() < si.child_t) si.child_t = o->y();
	if (o->x()+o->w() > si.child_r) si.child_r = o->x()+o->w();
	if (o->y()+o->h() > si.child_b) si.child_b = o->y()+o->h();
    }
  }

  // Turn the scrollbars on and off as necessary.
  // See if children would fit if we had no scrollbars...
  {
    int X = si.innerbox_x;
    int Y = si.innerbox_y;
    int W = si.innerbox_w;
    int H = si.innerbox_h;

    si.scrollsize = scrollbar_size_ ? scrollbar_size_ : Fl::scrollbar_size();
    si.vneeded = 0;
    si.hneeded = 0;
    if (type() & VERTICAL) {
      if ((type() & ALWAYS_ON) || si.child_t < Y || si.child_b > Y+H) {
	si.vneeded = 1;
	W -= si.scrollsize;
	if (scrollbar.align() & FL_ALIGN_LEFT) X += si.scrollsize;
      }
    }
    if (type() & HORIZONTAL) {
      if ((type() & ALWAYS_ON) || si.child_l < X || si.child_r > X+W) {
	si.hneeded = 1;
	H -= si.scrollsize;
	if (scrollbar.align() & FL_ALIGN_TOP) Y += si.scrollsize;
	// recheck vertical since we added a horizontal scrollbar
	if (!si.vneeded && (type() & VERTICAL)) {
	  if ((type() & ALWAYS_ON) || si.child_t < Y || si.child_b > Y+H) {
	    si.vneeded = 1;
	    W -= si.scrollsize;
	    if (scrollbar.align() & FL_ALIGN_LEFT) X += si.scrollsize;
	  }
	}
      }
    }
    si.innerchild_x = X;
    si.innerchild_y = Y;
    si.innerchild_w = W;
    si.innerchild_h = H;
  }

  // calculate hor scrollbar position
  si.hscroll_x = si.innerchild_x;
  si.hscroll_y = (scrollbar.align() & FL_ALIGN_TOP) 
		     ? si.innerbox_y
		     : si.innerbox_y + si.innerbox_h - si.scrollsize;
  si.hscroll_w = si.innerchild_w;
  si.hscroll_h = si.scrollsize;

  // calculate ver scrollbar position
  si.vscroll_x = (scrollbar.align() & FL_ALIGN_LEFT)
                     ? si.innerbox_x
		     : si.innerbox_x + si.innerbox_w - si.scrollsize;
  si.vscroll_y = si.innerchild_y;
  si.vscroll_w = si.scrollsize;
  si.vscroll_h = si.innerchild_h;

  // calculate h/v scrollbar values (pos/size/first/total)
  si.hpos = si.innerchild_x - si.child_l;
  si.hsize = si.innerchild_w;
  si.hfirst = 0;
  si.htotal = si.child_r - si.child_l;
  if ( si.hpos < 0 ) { si.htotal += (-si.hpos); si.hfirst = si.hpos; }

  si.vpos = si.innerchild_y - si.child_t;
  si.vsize = si.innerchild_h;
  si.vfirst = 0;
  si.vtotal = si.child_b - si.child_t;
  if ( si.vpos < 0 ) { si.vtotal += (-si.vpos); si.vfirst = si.vpos; }

//  printf("DEBUG --- ScrollInfo ---\n");
//  printf("DEBUG        scrollsize: %d\n", si.scrollsize);
//  printf("DEBUG  hneeded, vneeded: %d %d\n", si.hneeded, si.vneeded);
//  printf("DEBUG     innerbox xywh: %d %d %d %d\n", si.innerbox_x,   si.innerbox_y,   si.innerbox_w,   si.innerbox_h);
//  printf("DEBUG   innerchild xywh: %d %d %d %d\n", si.innerchild_x, si.innerchild_y, si.innerchild_w, si.innerchild_h);
//  printf("DEBUG        child lrbt: %d %d %d %d\n", si.child_l, si.child_r, si.child_b, si.child_t);
//  printf("DEBUG      hscroll xywh: %d %d %d %d\n", si.hscroll_x, si.hscroll_y, si.hscroll_w, si.hscroll_h);
//  printf("DEBUG      vscroll xywh: %d %d %d %d\n", si.vscroll_x, si.vscroll_y, si.vscroll_w, si.vscroll_h);
//  printf("DEBUG  horz scroll vals: %d %d %d %d\n", si.hpos, si.hsize, si.hfirst, si.htotal);
//  printf("DEBUG  vert scroll vals: %d %d %d %d\n", si.vpos, si.vsize, si.vfirst, si.vtotal);
//  printf("DEBUG \n");
}