void Fl_Choice::draw() {
  int dx = Fl::box_dx(FL_DOWN_BOX);
  int dy = Fl::box_dy(FL_DOWN_BOX);
  int H = h() - 2 * dy;
  int W = (H > 20) ? 20 : H;
  int X = x() + w() - W - dx;
  int Y = y() + dy;
  int w1 = (W - 4) / 3; if (w1 < 1) w1 = 1;
  int x1 = X + (W - 2 * w1 - 1) / 2;
  int y1 = Y + (H - w1 - 1) / 2;

  if (Fl::scheme()) {
    draw_box(FL_UP_BOX, color());

    fl_color(active_r() ? labelcolor() : fl_inactive(labelcolor()));
    if (!strcmp(Fl::scheme(), "plastic")) {
      // Show larger up/down arrows...
      fl_polygon(x1, y1 + 3, x1 + w1, y1 + w1 + 3, x1 + 2 * w1, y1 + 3);
      fl_polygon(x1, y1 + 1, x1 + w1, y1 - w1 + 1, x1 + 2 * w1, y1 + 1);
    } else {
      // Show smaller up/down arrows with a divider...
      x1 = x() + w() - 13 - dx;
      y1 = y() + h() / 2;
      fl_polygon(x1, y1 - 2, x1 + 3, y1 - 5, x1 + 6, y1 - 2);
      fl_polygon(x1, y1 + 2, x1 + 3, y1 + 5, x1 + 6, y1 + 2);

      fl_color(fl_darker(color()));
      fl_yxline(x1 - 7, y1 - 8, y1 + 8);

      fl_color(fl_lighter(color()));
      fl_yxline(x1 - 6, y1 - 8, y1 + 8);
    }
  } else {
    if (fl_contrast(textcolor(), FL_BACKGROUND2_COLOR) == textcolor()) {
      draw_box(FL_DOWN_BOX, FL_BACKGROUND2_COLOR);
    } else {
      draw_box(FL_DOWN_BOX, fl_lighter(color()));
    }
    draw_box(FL_UP_BOX,X,Y,W,H,color());

    fl_color(active_r() ? labelcolor() : fl_inactive(labelcolor()));
    fl_polygon(x1, y1, x1 + w1, y1 + w1, x1 + 2 * w1, y1);
  }

  W += 2 * dx;

  if (mvalue()) {
    Fl_Menu_Item m = *mvalue();
    if (active_r()) m.activate(); else m.deactivate();

    // ERCO
    int xx = x() + dx, yy = y() + dy + 1, ww = w() - W, hh = H - 2;

    fl_push_clip(xx, yy, ww, hh);

    if ( Fl::scheme()) {
      Fl_Label l;
      l.value = m.text;
      l.image = 0;
      l.deimage = 0;
      l.type = m.labeltype_;
      l.font = m.labelsize_ || m.labelfont_ ? m.labelfont_ : textfont();
      l.size = m.labelsize_ ? m.labelsize_ : textsize();
      l.color= m.labelcolor_ ? m.labelcolor_ : textcolor();
      if (!m.active()) l.color = fl_inactive((Fl_Color)l.color);
      fl_draw_shortcut = 2; // hack value to make '&' disappear
      l.draw(xx+3, yy, ww>6 ? ww-6 : 0, hh, FL_ALIGN_LEFT);
      fl_draw_shortcut = 0;
      if ( Fl::focus() == this ) draw_focus(box(), xx, yy, ww, hh);
    }
    else {
      fl_draw_shortcut = 2; // hack value to make '&' disappear
      m.draw(xx, yy, ww, hh, this, Fl::focus() == this);
      fl_draw_shortcut = 0;
    }

    fl_pop_clip();
  }

  draw_label();
}