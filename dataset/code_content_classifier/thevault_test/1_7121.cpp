int Fl_Text_Editor::kf_cut(int c, Fl_Text_Editor* e) {
  kf_copy(c, e);
  kill_selection(e);
  e->set_changed();
  if (e->when()&FL_WHEN_CHANGED) e->do_callback();
  return 1;
}