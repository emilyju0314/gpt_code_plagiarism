int Fl_Text_Editor::kf_c_s_move(int c, Fl_Text_Editor* e) {
  kf_ctrl_move(c, e);
  fl_text_drag_me(e->insert_position(), e);
  return 1;
}