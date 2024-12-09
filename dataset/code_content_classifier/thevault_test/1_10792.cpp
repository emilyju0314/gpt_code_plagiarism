void TextlineProjection::IncrementRectangle8Bit(const TBOX &box) {
  int scaled_left = ImageXToProjectionX(box.left());
  int scaled_top = ImageYToProjectionY(box.top());
  int scaled_right = ImageXToProjectionX(box.right());
  int scaled_bottom = ImageYToProjectionY(box.bottom());
  int wpl = pixGetWpl(pix_);
  uint32_t *data = pixGetData(pix_) + scaled_top * wpl;
  for (int y = scaled_top; y <= scaled_bottom; ++y) {
    for (int x = scaled_left; x <= scaled_right; ++x) {
      int pixel = GET_DATA_BYTE(data, x);
      if (pixel < 255) {
        SET_DATA_BYTE(data, x, pixel + 1);
      }
    }
    data += wpl;
  }
}