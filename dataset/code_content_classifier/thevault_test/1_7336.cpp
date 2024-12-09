void fl_rectbound(int x, int y, int w, int h, Fl_Color bgcolor) {
  fl_color(draw_it_active ? FL_BLACK : fl_inactive(FL_BLACK));
  fl_rect(x, y, w, h);
  fl_color(draw_it_active ? bgcolor : fl_inactive(bgcolor));
  fl_rectf(x+1, y+1, w-2, h-2);
}