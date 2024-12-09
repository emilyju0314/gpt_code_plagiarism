void fl_throw_focus(Fl_Widget *o) {
#ifdef DEBUG
  printf("fl_throw_focus(o=%p)\n", o);
#endif // DEBUG

  if (o->contains(Fl::pushed())) Fl::pushed_ = 0;
#ifndef WIN32
  if (o->contains(fl_selection_requestor)) fl_selection_requestor = 0;
#endif
  if (o->contains(Fl::belowmouse())) Fl::belowmouse_ = 0;
  if (o->contains(Fl::focus())) Fl::focus_ = 0;
  if (o == fl_xfocus) fl_xfocus = 0;
  if (o == Fl_Tooltip::current()) Fl_Tooltip::current(0);
  if (o == fl_xmousewin) fl_xmousewin = 0;
  Fl_Tooltip::exit(o);
  fl_fix_focus();
}