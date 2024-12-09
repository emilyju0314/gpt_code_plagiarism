bool TFT_eSprite::pushRotated(int16_t angle, int32_t transp)
{
  if ( !_created ) return false;

  // Trig values for the rotation
  float radAngle = -angle * 0.0174532925; // Convert degrees to radians
  float sinra = sin(radAngle);
  float cosra = cos(radAngle);

  // Bounding box parameters
  int16_t min_x;
  int16_t min_y;
  int16_t max_x;
  int16_t max_y;

  // Get the bounding box of this rotated source Sprite relative to Sprite pivot
  getRotatedBounds(sinra, cosra, width(), height(), _xpivot, _ypivot, &min_x, &min_y, &max_x, &max_y);

  // Move bounding box so source Sprite pivot coincides with TFT pivot
  min_x += _tft->_xpivot;
  max_x += _tft->_xpivot;
  min_y += _tft->_ypivot;
  max_y += _tft->_ypivot;

  // Test only to show bounding box on TFT
  // _tft->drawRect(min_x, min_y, max_x - min_x + 1, max_y - min_y + 1, TFT_GREEN);

  // Return if bounding box is outside of TFT area
  if (min_x > _tft->width()) return true;
  if (min_y > _tft->height()) return true;
  if (max_x < 0) return true;
  if (max_y < 0) return true;

  // Clip bounding box to be within TFT area
  if (min_x < 0) min_x = 0;
  if (min_y < 0) min_y = 0;
  if (max_x > _tft->width()) max_x = _tft->width();
  if (max_y > _tft->height()) max_y = _tft->height();

  _tft->startWrite(); // ESP32: avoid transaction overhead for every tft pixel

  // Scan destination bounding box and fetch transformed pixels from source Sprite
  for (int32_t x = min_x; x <= max_x; x++) {
    int32_t xt = x - _tft->_xpivot;
    float cxt = cosra * xt + _xpivot;
    float sxt = sinra * xt + _ypivot;
    bool column_drawn = false;
    for (int32_t y = min_y; y <= max_y; y++) {
      int32_t yt = y - _tft->_ypivot;
      int32_t xs = (int32_t)round(cxt - sinra * yt);
      // Do not calculate ys unless xs is in bounds
      if (xs >= 0 && xs < width())
      {
        int32_t ys = (int32_t)round(sxt + cosra * yt);
        // Check if ys is in bounds
        if (ys >= 0 && ys < height()) {
          int32_t rp = readPixel(xs, ys);
          if (rp != transp) _tft->drawPixel(x, y, rp);
          column_drawn = true;
        }
      }
      else if (column_drawn) y = max_y; // Skip remaining column pixels
    }
  }

  _tft->endWrite(); // ESP32: end transaction

  return true;
}