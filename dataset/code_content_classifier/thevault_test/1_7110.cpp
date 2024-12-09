int Fl_Text_Editor::kf_default(int c, Fl_Text_Editor* e) {
  // FIXME: this function is a mess! Fix this!
  if (!c || (!isprint(c) && c != '\t')) return 0;
  char s[2] = "\0";
  s[0] = (char)c;
  kill_selection(e);
  if (e->insert_mode()) e->insert(s);
  else e->overstrike(s);
  e->show_insert_position();
  e->set_changed();
  if (e->when()&FL_WHEN_CHANGED) e->do_callback();
  return 1;
}