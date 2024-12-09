void Fl_Slider::draw_bg(int X, int Y, int W, int H) {
  fl_push_clip(X, Y, W, H);
  draw_box();
  fl_pop_clip();

  Fl_Color black = active_r() ? FL_FOREGROUND_COLOR : FL_INACTIVE_COLOR;
  if (type() == FL_VERT_NICE_SLIDER) {
    draw_box(FL_THIN_DOWN_BOX, X+W/2-2, Y, 4, H, black);
  } else if (type() == FL_HOR_NICE_SLIDER) {
    draw_box(FL_THIN_DOWN_BOX, X, Y+H/2-2, W, 4, black);
  }
}