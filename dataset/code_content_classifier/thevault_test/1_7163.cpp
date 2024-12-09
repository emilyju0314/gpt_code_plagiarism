void Fl_Text_Display::clear_rect(int style, 
                                 int X, int Y,
                                 int width, int height) const {
  /* A width of zero means "clear to end of window" to XClearArea */
  if ( width == 0 )
    return;
  
  if (style & PRIMARY_MASK) {
    if (Fl::focus()==this) {
      fl_color(selection_color());
    } else {
      fl_color(fl_color_average(color(), selection_color(), 0.4f));
    }
  } else if (style & HIGHLIGHT_MASK) {
    if (Fl::focus()==this) {
      fl_color(fl_color_average(color(), selection_color(), 0.5f));
    } else {
      fl_color(fl_color_average(color(), selection_color(), 0.6f));
    }
  } else {
    fl_color( color() );
  }
  fl_rectf( X, Y, width, height );
}