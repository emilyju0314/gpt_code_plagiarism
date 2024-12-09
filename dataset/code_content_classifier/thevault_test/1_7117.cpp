int Fl_Text_Editor::kf_m_s_move(int c, Fl_Text_Editor* e) {
  kf_meta_move(c, e);
  fl_text_drag_me(e->insert_position(), e);
  return 1;
}