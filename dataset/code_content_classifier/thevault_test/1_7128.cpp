Fl_Text_Display::~Fl_Text_Display() {
  if (scroll_direction) {
    Fl::remove_timeout(scroll_timer_cb, this);
    scroll_direction = 0;
  }
  if (mBuffer) {
    mBuffer->remove_modify_callback(buffer_modified_cb, this);
    mBuffer->remove_predelete_callback(buffer_predelete_cb, this);
  }
  if (mLineStarts) delete[] mLineStarts;
}