void* TFT_eSprite::frameBuffer(int8_t f)
{
  if (!_created) return NULL;

  if (_bpp == 16) return _img;

  if (_bpp == 8) return _img8;

  if ( f == 2 ) _img8 = _img8_2;
  else          _img8 = _img8_1;

  return _img8;
}