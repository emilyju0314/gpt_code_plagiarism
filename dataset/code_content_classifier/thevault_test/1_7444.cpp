void TFT_eSprite::drawFastVLine(int32_t x, int32_t y, int32_t h, uint32_t color)
{

  if ((x < 0) || (x >= _iwidth) || (y >= _iheight) || !_created) return;

  if (y < 0) { h += y; y = 0; }

  if ((y + h) > _iheight) h = _iheight - y;

  if (h < 1) return;

  if (_bpp == 16)
  {
    color = (color >> 8) | (color << 8);
    int32_t yp = x + _iwidth * y;
    while (h--) {_img[yp] = (uint16_t) color; yp += _iwidth;}
  }
  else if (_bpp == 8)
  {
    color = (color & 0xE000)>>8 | (color & 0x0700)>>6 | (color & 0x0018)>>3;
    while (h--) _img8[x + _iwidth * y++] = (uint8_t) color;
  }
  else
  {
    while (h--)
    {
      drawPixel(x, y, color);
      y++;
    }
  }
}