void Fl_Text_Display::previous_word() {
  int pos = insert_position();
  if (pos==0) return;
  pos = buffer()->prev_char(pos);

  while (pos && fl_isseparator(buffer()->char_at(pos))) {
    pos = buffer()->prev_char(pos);
  }

  while (pos && !fl_isseparator(buffer()->char_at(pos))) {
    pos = buffer()->prev_char(pos);
  }

  if (fl_isseparator(buffer()->char_at(pos))) {
    pos = buffer()->next_char(pos);
  }
  
  insert_position( pos );
}