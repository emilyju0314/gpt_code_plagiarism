bool TFT_eSprite::pushRotated(TFT_eSprite *spr, int16_t angle, int32_t transp)
{
  if ( !_created ) return false;       // Check this Sprite is created
  if ( !spr->_created ) return false;  // Ckeck destination Sprite is created

  // Trig values for the rotation
  float radAngle = -angle * 0.0174532925; // Convert degrees to radians
  float sinra = sin(radAngle);
  float cosra = cos(radAngle);

  // Bounding box parameters
  int16_t min_x;
  int16_t min_y;
  int16_t max_x;
  int16_t max_y;

  // Get the bounding box of this rotated source Sprite
  getRotatedBounds(sinra, cosra, width(), height(), _xpivot, _ypivot, &min_x, &min_y, &max_x, &max_y);

  // Move bounding box so source Sprite pivot coincides with destination Sprite pivot
  min_x += spr->_xpivot;
  max_x += spr->_xpivot;
  min_y += spr->_ypivot;
  max_y += spr->_ypivot;

  // Test only to show bounding box
  // spr->fillSprite(TFT_BLACK);
  // spr->drawRect(min_x, min_y, max_x - min_x + 1, max_y - min_y + 1, TFT_GREEN);

  // Return if bounding box is completely outside of destination Sprite
  if (min_x > spr->width()) return true;
  if (min_y > spr->height()) return true;
  if (max_x < 0) return true;
  if (max_y < 0) return true;

  // Clip bounding box if it is partially within destination Sprite
  if (min_x < 0) min_x = 0;
  if (min_y < 0) min_y = 0;
  if (max_x > spr->width()) max_x = spr->width();
  if (max_y > spr->height()) max_y = spr->height();

  // Scan destination bounding box and fetch transformed pixels from source Sprite
  for (int32_t x = min_x; x <= max_x; x++)
  {
    int32_t xt = x - spr->_xpivot;
    float cxt = cosra * xt + _xpivot;
    float sxt = sinra * xt + _ypivot;
    bool column_drawn = false;
    for (int32_t y = min_y; y <= max_y; y++)
    {
      int32_t yt = y - spr->_ypivot;
      int32_t xs = (int32_t)round(cxt - sinra * yt);
      // Do not calculate ys unless xs is in bounds
      if (xs >= 0 && xs < width())
      {
        int32_t ys = (int32_t)round(sxt + cosra * yt);
        // Check if ys is in bounds
        if (ys >= 0 && ys < height())
        {
          int32_t rp = readPixel(xs, ys);
          if (rp != transp) spr->drawPixel(x, y, rp);
          column_drawn = true;
        }
      }
      else if (column_drawn) y = max_y; // Skip the remaining pixels below the Sprite
    }
  }

  return true;
}