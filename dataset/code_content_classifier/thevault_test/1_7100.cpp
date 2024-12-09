void Flmm_Tabs::draw_tab(int x1, int x2, int W, int H, Fl_Widget* o, int what) {
  x1 -= xoff; x2 -= xoff;
  int sel = (what == SELECTED);
  int dh = Fl::box_dh(box());
  int dy = Fl::box_dy(box());

  // compute offsets to make selected tab look bigger
  int yofs = sel ? 0 : BORDER;

  if ((x2 < x1+W) && what == RIGHT) x1 = x2 - W;

  if (H >= 0) {
    if (sel) fl_clip(x1, y(), x2 - x1, H + dh - dy);
    else fl_clip(x1, y(), x2 - x1, H);

    H += dh;

    Fl_Color c = sel ? selection_color() : o->selection_color();

    draw_box(box(), x1, y() + yofs, W, H + 10 - yofs, c);

    // Save the previous label color
    Fl_Color oc = o->labelcolor();

    // Draw the label using the current color...
    o->labelcolor(sel ? labelcolor() : o->labelcolor());    
    o->draw_label(x1, y() + yofs, W, H - yofs, FL_ALIGN_CENTER);

    // Restore the original label color...
    o->labelcolor(oc);

    if (Fl::focus() == this && o->visible())
      draw_focus(box(), x1, y(), W, H);

    fl_pop_clip();
  } else {
    H = -H;

    if (sel) fl_clip(x1, y() + h() - H - dy, x2 - x1, H + dy);
    else fl_clip(x1, y() + h() - H, x2 - x1, H);

    H += dh;

    Fl_Color c = sel ? selection_color() : o->selection_color();

    draw_box(box(), x1, y() + h() - H - 10, W, H + 10 - yofs, c);

    // Save the previous label color
    Fl_Color oc = o->labelcolor();

    // Draw the label using the current color...
    o->labelcolor(sel ? labelcolor() : o->labelcolor());
    o->draw_label(x1, y() + h() - H, W, H - yofs, FL_ALIGN_CENTER);

    // Restore the original label color...
    o->labelcolor(oc);

    if (Fl::focus() == this && o->visible())
      draw_focus(box(), x1, y() + h() - H, W, H);

    fl_pop_clip();
  }
}