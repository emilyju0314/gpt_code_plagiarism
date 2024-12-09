void* TFT_eSprite::setColorDepth(int8_t b)
{
  // Can't change an existing sprite's colour depth so delete it
  if (_created) free(_img8_1);

  // Now define the new colour depth
  if ( b > 8 ) _bpp = 16;  // Bytes per pixel
  else if ( b > 1 ) _bpp = 8;
  else _bpp = 1;

  // If it existed, re-create the sprite with the new colour depth
  if (_created)
  {
    _created = false;
    return createSprite(_iwidth, _iheight);
  }

  return NULL;
}