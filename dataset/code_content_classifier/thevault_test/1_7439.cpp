int16_t TFT_eSprite::width(void)
{
  if (!_created ) return 0;

  if (_bpp > 1) return _iwidth;

  if (_rotation == 1 || _rotation == 3) return _dheight;

  return _dwidth;
}