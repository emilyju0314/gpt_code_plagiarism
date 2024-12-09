void Fl_X::q_fill_context() {
  if (!fl_gc) return;
  int hgt = 0;
  if (fl_window) {
    Rect portRect; 
    GetPortBounds(GetWindowPort( fl_window ), &portRect);
    hgt = portRect.bottom-portRect.top;
  } else {
    hgt = CGBitmapContextGetHeight(fl_gc);
  }
  CGContextTranslateCTM(fl_gc, 0.5, hgt-0.5f);
  CGContextScaleCTM(fl_gc, 1.0f, -1.0f);
  fl_font(fl_fontsize);
  fl_color(fl_color_);
  fl_quartz_restore_line_style_();
}