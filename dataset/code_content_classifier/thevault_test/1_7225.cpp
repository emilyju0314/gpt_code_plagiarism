void Fl::focus(Fl_Widget *o) {
  if (o && !o->visible_focus()) return;
  if (grab()) return; // don't do anything while grab is on
  Fl_Widget *p = focus_;
  if (o != p) {
    Fl::compose_reset();
    focus_ = o;
    // make sure that fl_xfocus is set to the top level window
    // of this widget, or fl_fix_focus will clear our focus again
    if (o) {
      Fl_Window *win = 0, *w1 = o->window();
      while (w1) { win=w1; w1=win->window(); }
      if (win) fl_xfocus = win;
    }
    // take focus from the old focused window
    fl_oldfocus = 0;
    int old_event = e_number;
    e_number = FL_UNFOCUS;
    for (; p; p = p->parent()) {
      p->handle(FL_UNFOCUS);
      fl_oldfocus = p;
    }
    e_number = old_event;
  }
}