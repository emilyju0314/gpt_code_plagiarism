void  TFT_eSprite::pushImage(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t *data)
{
  if ((x >= _iwidth) || (y >= _iheight) || (w == 0) || (h == 0) || !_created) return;
  if ((x + w < 0) || (y + h < 0)) return;

  int32_t  xo = 0;
  int32_t  yo = 0;

  int32_t  xs = x;
  int32_t  ys = y;

  int32_t ws = w;
  int32_t hs = h;

  if (x < 0) { xo = -x; ws += x; xs = 0; }
  if (y < 0) { yo = -y; hs += y; ys = 0; }

  if (xs + ws >= (int32_t)_iwidth)  ws = _iwidth  - xs;
  if (ys + hs >= (int32_t)_iheight) hs = _iheight - ys;

  if (_bpp == 16) // Plot a 16 bpp image into a 16 bpp Sprite
  {
    for (int32_t yp = yo; yp < yo + hs; yp++)
    {
      x = xs;
      for (int32_t xp = xo; xp < xo + ws; xp++)
      {
        uint16_t color =  data[xp + yp * w];
        if(!_iswapBytes) color = color<<8 | color>>8;
        _img[x + ys * _iwidth] = color;
        x++;
      }
      ys++;
    }
  }
  else if (_bpp == 8) // Plot a 16 bpp image into a 8 bpp Sprite
  {
    for (int32_t yp = yo; yp < yo + hs; yp++)
    {
      x = xs;
      for (int32_t xp = xo; xp < xo + ws; xp++)
      {
        uint16_t color = data[xp + yp * w];
        if(_iswapBytes) color = color<<8 | color>>8;
        _img8[x + ys * _iwidth] = (uint8_t)((color & 0xE000)>>8 | (color & 0x0700)>>6 | (color & 0x0018)>>3);
        x++;
      }
      ys++;
    }
  }

  else // 1bpp
  {
    // Move coordinate rotation to support fn
    if (_rotation == 1)
    {
      int32_t tx = x;
      x = _dwidth - y - 1;
      y = tx;
    }
    else if (_rotation == 2)
    {
      x = _dwidth - x - 1;
      y = _dheight - y - 1;
    }
    else if (_rotation == 3)
    {
      int32_t tx = x;
      x = y;
      y = _dheight - tx - 1;
    }
    // Plot a 1bpp image into a 1bpp Sprite
    uint8_t* pdata = (uint8_t* ) data;
    uint32_t ww =  (w+7) & 0xFFF8;
    for (int32_t yp = 0; yp<h; yp++)
    {
      uint32_t yw = (yp * ww)>>3;
      uint32_t yyp = y + yp;
      for (int32_t xp = 0; xp<w; xp++)
      {
        uint16_t readPixel = (pdata[(xp>>3) + yw] & (0x80 >> (xp & 0x7)) );
        drawPixel(x+xp, yyp, readPixel);
      }
    }
  }
}