void Fl_Text_Display::next_word() {
  int pos = insert_position();

  while (pos < buffer()->length() && !fl_isseparator(buffer()->char_at(pos))) {
    pos = buffer()->next_char(pos);
  }

  while (pos < buffer()->length() && fl_isseparator(buffer()->char_at(pos))) {
    pos = buffer()->next_char(pos);
  }
  
  insert_position( pos );
}