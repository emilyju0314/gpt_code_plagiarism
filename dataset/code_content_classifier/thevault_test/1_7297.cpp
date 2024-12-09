void Fl::background2(uchar r, uchar g, uchar b) {
  fl_bg2_set = 1;

  Fl::set_color(FL_BACKGROUND2_COLOR,r,g,b);
  Fl::set_color(FL_FOREGROUND_COLOR,
                get_color(fl_contrast(FL_FOREGROUND_COLOR,FL_BACKGROUND2_COLOR)));
}