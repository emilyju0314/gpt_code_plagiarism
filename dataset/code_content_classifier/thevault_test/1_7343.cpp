static XFontStruct* load_xfont_for_xft2(void) {
  XFontStruct* xgl_font = 0;
  int size = fl_size_;
  const char *wt_med = "medium";
  const char *wt_bold = "bold";
  const char *weight = wt_med; // no specifc weight requested - accept any
  char slant = 'r';   // regular non-italic by default
  char xlfd[128];     // we will put our synthetic XLFD in here
  char *pc = strdup(fl_fonts[fl_font_].name); // what font were we asked for?
  const char *name = pc;    // keep a handle to the original name for freeing later
  // Parse the "fltk-name" of the font
  switch (*name++) {
  case 'I': slant = 'i'; break;       // italic
  case 'P': slant = 'i';              // bold-italic (falls-through)
  case 'B': weight = wt_bold; break;  // bold
  case ' ': break;                    // regular
  default: name--;                    // no prefix, restore name
  }

  // first, we do a query with no prefered size, to see if the font exists at all
  snprintf(xlfd, 128, "-*-%s-%s-%c-*--*-*-*-*-*-*-*-*", name, weight, slant); // make up xlfd style name
  xgl_font = XLoadQueryFont(fl_display, xlfd);
  if(xgl_font) { // the face exists, but can we get it in a suitable size?
    XFreeFont(fl_display, xgl_font); // release the non-sized version
    snprintf(xlfd, 128, "-*-%s-%s-%c-*--*-%d-*-*-*-*-*-*", name, weight, slant, (size*10));
    xgl_font = XLoadQueryFont(fl_display, xlfd); // attempt to load the font at the right size
  }
//puts(xlfd);

  // try alternative names
  if (!xgl_font) {
    if (!strcmp(name, "sans")) {
      name = "helvetica";
    } else if (!strcmp(name, "mono")) {
      name = "courier";
    } else if (!strcmp(name, "serif")) {
      name = "times";
    } else if (!strcmp(name, "screen")) {
      name = "lucidatypewriter";
    } else if (!strcmp(name, "dingbats")) {
      name = "zapf dingbats";
    }
    snprintf(xlfd, 128, "-*-*%s*-%s-%c-*--*-%d-*-*-*-*-*-*", name, weight, slant, (size*10));
    xgl_font = XLoadQueryFont(fl_display, xlfd);
  }  
  free(pc); // release our copy of the font name
  
  // if we have nothing loaded, try a generic proportional font
  if(!xgl_font) {
    snprintf(xlfd, 128, "-*-helvetica-*-%c-*--*-%d-*-*-*-*-*-*", slant, (size*10));
    xgl_font = XLoadQueryFont(fl_display, xlfd);
  }
  // If that still didn't work, try this instead
  if(!xgl_font) {
    snprintf(xlfd, 128, "-*-courier-medium-%c-*--*-%d-*-*-*-*-*-*", slant, (size*10));
    xgl_font = XLoadQueryFont(fl_display, xlfd);
  }
//printf("glf: %d\n%s\n%s\n", size, xlfd, fl_fonts[fl_font_].name);
//if(xgl_font) puts("ok");

  // Last chance fallback - this usually loads something...
  if (!xgl_font) xgl_font = XLoadQueryFont(fl_display, "fixed");

  return xgl_font;
}