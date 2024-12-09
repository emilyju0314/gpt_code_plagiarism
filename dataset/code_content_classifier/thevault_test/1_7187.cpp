double Fl_Text_Display::col_to_x(double col) const
{
  if (!mColumnScale) {
    // recalculate column scale value
    x_to_col(0); 
  }
  return col*mColumnScale;
}