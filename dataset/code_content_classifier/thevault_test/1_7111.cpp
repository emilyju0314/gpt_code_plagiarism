int Fl_Text_Editor::kf_backspace(int, Fl_Text_Editor* e) {
  if (!e->buffer()->selected() && e->move_left()) {
    int p1 = e->insert_position();
    int p2 = e->buffer()->next_char(p1);
    e->buffer()->select(p1, p2);
  }
  kill_selection(e);
  e->show_insert_position();
  e->set_changed();
  if (e->when()&FL_WHEN_CHANGED) e->do_callback();
  return 1;
}