void Fl_Tile::position(int oix, int oiy, int newx, int newy) {
  Fl_Widget*const* a = array();
  int *p = sizes();
  p += 8; // skip group & resizable's saved size
  for (int i=children(); i--; p += 4) {
    Fl_Widget* o = *a++;
    if (o == resizable()) continue;
    int X = o->x();
    int R = X+o->w();
    if (oix) {
      int t = p[0];
      if (t == oix || (t>oix && X<newx) || (t<oix && X>newx) ) X = newx;
      t = p[1];
      if (t == oix || (t>oix && R<newx) || (t<oix && R>newx) ) R = newx;
    }
    int Y = o->y();
    int B = Y+o->h();
    if (oiy) {
      int t = p[2];
      if (t == oiy || (t>oiy && Y<newy) || (t<oiy && Y>newy) ) Y = newy;
      t = p[3];
      if (t == oiy || (t>oiy && B<newy) || (t<oiy && B>newy) ) B = newy;
    }
    o->damage_resize(X,Y,R-X,B-Y);
  }
}