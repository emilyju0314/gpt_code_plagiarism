int Fl_Text_Editor::kf_shift_move(int c, Fl_Text_Editor* e) {
  kf_move(c, e);
  fl_text_drag_me(e->insert_position(), e);
  return 1;
}