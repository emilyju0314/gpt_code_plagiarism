void TFT_eSprite::setWindow(int32_t x0, int32_t y0, int32_t x1, int32_t y1)
{
  if (x0 > x1) swap_coord(x0, x1);
  if (y0 > y1) swap_coord(y0, y1);

  if ((x0 >= _iwidth) || (x1 < 0) || (y0 >= _iheight) || (y1 < 0))
  { // Point to that extra "off screen" pixel
    _xs = 0;
    _ys = _iheight;
    _xe = 0;
    _ye = _iheight;
  }
  else
  {
    if (x0 < 0) x0 = 0;
    if (x1 >= _iwidth) x1 = _iwidth - 1;
    if (y0 < 0) y0 = 0;
    if (y1 >= _iheight) y1 = _iheight - 1;

    _xs = x0;
    _ys = y0;
    _xe = x1;
    _ye = y1;
  }

  _xptr = _xs;
  _yptr = _ys;
}