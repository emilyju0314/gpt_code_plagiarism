int Fl_Text_Editor::kf_enter(int, Fl_Text_Editor* e) {
  kill_selection(e);
  e->insert("\n");
  e->show_insert_position();
  e->set_changed();
  if (e->when()&FL_WHEN_CHANGED) e->do_callback();
  return 1;
}