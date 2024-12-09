int16_t TFT_eSprite::height(void)
{
  if (!_created ) return 0;

  if (_bpp > 1) return _iheight;

  if (_rotation == 1 || _rotation == 3) return _dwidth;

  return _dheight;
}