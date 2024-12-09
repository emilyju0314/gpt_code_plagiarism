void Fl::belowmouse(Fl_Widget *o) {
  if (grab()) return; // don't do anything while grab is on
  Fl_Widget *p = belowmouse_;
  if (o != p) {
    belowmouse_ = o;
    int old_event = e_number;
    e_number = dnd_flag ? FL_DND_LEAVE : FL_LEAVE;
    for (; p && !p->contains(o); p = p->parent()) {
      p->handle(e_number);
    }
    e_number = old_event;
  }
}