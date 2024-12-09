void TFT_eSprite::deleteSprite(void)
{
  if (!_created ) return;

  free(_img8_1);

  _created = false;
}