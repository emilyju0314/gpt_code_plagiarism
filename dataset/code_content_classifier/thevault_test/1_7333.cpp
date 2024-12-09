void fl_up_box(int x, int y, int w, int h, Fl_Color c) {
  fl_up_frame(x,y,w,h,c);
  fl_color(draw_it_active ? c : fl_inactive(c));
  fl_rectf(x+D1, y+D1, w-D2, h-D2);
}