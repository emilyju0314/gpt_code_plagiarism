void Fl_Text_Display::scroll(int topLineNum, int horizOffset) {
  mTopLineNumHint = topLineNum;
  mHorizOffsetHint = horizOffset;
  resize(x(), y(), w(), h());
}