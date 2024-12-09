void TFT_eSprite::setRotation(uint8_t rotation)
{
  if (_bpp != 1) return;

  _rotation = rotation;
  if (rotation == 0 && _iwidth > _iheight) swap_coord(_iwidth, _iheight);
  if (rotation == 1 && _iwidth < _iheight) swap_coord(_iwidth, _iheight);
  if (rotation == 2 && _iwidth > _iheight) swap_coord(_iwidth, _iheight);
  if (rotation == 3 && _iwidth < _iheight) swap_coord(_iwidth, _iheight);
}