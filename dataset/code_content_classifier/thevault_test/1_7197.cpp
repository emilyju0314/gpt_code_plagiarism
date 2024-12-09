void fl_free_fonts(void)
{
// remove the Fl_Font_Descriptor chains
  int i;
  Fl_Fontdesc * s;
  Fl_Font_Descriptor * f;
  Fl_Font_Descriptor * ff;
  for (i=0; i<FL_FREE_FONT; i++) {
    s = fl_fonts + i;
    for (f=s->first; f; f=ff) {
      ff = f->next;
      delete f;
      s->first = ff;
    }
  }
}