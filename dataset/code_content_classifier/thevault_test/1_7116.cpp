int Fl_Text_Editor::kf_meta_move(int c, Fl_Text_Editor* e) {
  if (!e->buffer()->selected())
    e->dragPos = e->insert_position();
  if (c != FL_Up && c != FL_Down) {
    e->buffer()->unselect();
    e->show_insert_position();
  }
  switch (c) {
    case FL_Up:				// top of buffer
      e->insert_position(0);
      e->scroll(0, 0);
      break;
    case FL_Down:			// end of buffer
      e->insert_position(e->buffer()->length());
      e->scroll(e->count_lines(0, e->buffer()->length(), 1), 0);
      break;
    case FL_Left:			// beginning of line
      kf_move(FL_Home, e);
      break;
    case FL_Right:			// end of line
      kf_move(FL_End, e);
      break;
  }
  return 1;
}