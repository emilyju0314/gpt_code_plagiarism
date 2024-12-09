double Fl_Text_Display::x_to_col(double y) const
{
  if (!mColumnScale) {
    mColumnScale = string_width("Mitg", 4, 'A') / 4.0;
  }
  return (y/mColumnScale)+0.5;
}