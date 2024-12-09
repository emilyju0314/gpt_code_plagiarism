void fl_text_drag_me(int pos, Fl_Text_Display* d) {
  if (d->dragType == Fl_Text_Display::DRAG_CHAR) {
    if (pos >= d->dragPos) {
      d->buffer()->select(d->dragPos, pos);
    } else {
      d->buffer()->select(pos, d->dragPos);
    }
    d->insert_position(pos);
  } else if (d->dragType == Fl_Text_Display::DRAG_WORD) {
    if (pos >= d->dragPos) {
      d->insert_position(d->word_end(pos));
      d->buffer()->select(d->word_start(d->dragPos), d->word_end(pos));
    } else {
      d->insert_position(d->word_start(pos));
      d->buffer()->select(d->word_start(pos), d->word_end(d->dragPos));
    }
  } else if (d->dragType == Fl_Text_Display::DRAG_LINE) {
    if (pos >= d->dragPos) {
      d->insert_position(d->buffer()->line_end(pos)+1);
      d->buffer()->select(d->buffer()->line_start(d->dragPos),
                          d->buffer()->line_end(pos)+1);
    } else {
      d->insert_position(d->buffer()->line_start(pos));
      d->buffer()->select(d->buffer()->line_start(pos),
                          d->buffer()->line_end(d->dragPos)+1);
    }
  }
}