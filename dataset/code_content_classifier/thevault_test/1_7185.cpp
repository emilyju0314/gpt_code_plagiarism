void Fl_Text_Display::scroll_timer_cb(void *user_data) {
  Fl_Text_Display *w = (Fl_Text_Display*)user_data;
  int pos;
  switch (scroll_direction) {
    case 1: // mouse is to the right, scroll left
      w->scroll(w->mTopLineNum, w->mHorizOffset + scroll_amount);
      pos = w->xy_to_position(w->text_area.x + w->text_area.w, scroll_y, CURSOR_POS);
      break;
    case 2: // mouse is to the left, scroll right
      w->scroll(w->mTopLineNum, w->mHorizOffset + scroll_amount);
      pos = w->xy_to_position(w->text_area.x, scroll_y, CURSOR_POS);
      break;
    case 3: // mouse is above, scroll down
      w->scroll(w->mTopLineNum + scroll_amount, w->mHorizOffset);
      pos = w->xy_to_position(scroll_x, w->text_area.y, CURSOR_POS);
      break;
    case 4: // mouse is below, scroll up
      w->scroll(w->mTopLineNum + scroll_amount, w->mHorizOffset);
      pos = w->xy_to_position(scroll_x, w->text_area.y + w->text_area.h, CURSOR_POS);
      break;
    default:
      return;
  }
  fl_text_drag_me(pos, w);
  Fl::repeat_timeout(.1, scroll_timer_cb, user_data);
}