int Fl_Text_Editor::kf_move(int c, Fl_Text_Editor* e) {
  int i;
  int selected = e->buffer()->selected();
  if (!selected)
    e->dragPos = e->insert_position();
  e->buffer()->unselect();
  switch (c) {
  case FL_Home:
      e->insert_position(e->buffer()->line_start(e->insert_position()));
      break;
    case FL_End:
      e->insert_position(e->buffer()->line_end(e->insert_position()));
      break;
    case FL_Left:
      e->move_left();
      break;
    case FL_Right:
      e->move_right();
      break;
    case FL_Up:
      e->move_up();
      break;
    case FL_Down:
      e->move_down();
      break;
    case FL_Page_Up:
      for (i = 0; i < e->mNVisibleLines - 1; i++) e->move_up();
      break;
    case FL_Page_Down:
      for (i = 0; i < e->mNVisibleLines - 1; i++) e->move_down();
      break;
  }
  e->show_insert_position();
  return 1;
}