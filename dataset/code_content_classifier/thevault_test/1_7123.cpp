int Fl_Text_Editor::kf_undo(int , Fl_Text_Editor* e) {
  e->buffer()->unselect();
  int crsr;
  int ret = e->buffer()->undo(&crsr);
  e->insert_position(crsr);
  e->show_insert_position();
  e->set_changed();
  if (e->when()&FL_WHEN_CHANGED) e->do_callback();
  return ret;
}