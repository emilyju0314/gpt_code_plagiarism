void TextlineProjection::DisplayProjection() const {
  int width = pixGetWidth(pix_);
  int height = pixGetHeight(pix_);
  Image pixc = pixCreate(width, height, 32);
  int src_wpl = pixGetWpl(pix_);
  int col_wpl = pixGetWpl(pixc);
  uint32_t *src_data = pixGetData(pix_);
  uint32_t *col_data = pixGetData(pixc);
  for (int y = 0; y < height; ++y, src_data += src_wpl, col_data += col_wpl) {
    for (int x = 0; x < width; ++x) {
      int pixel = GET_DATA_BYTE(src_data, x);
      l_uint32 result;
      if (pixel <= 17) {
        composeRGBPixel(0, 0, pixel * 15, &result);
      } else if (pixel <= 145) {
        composeRGBPixel(0, (pixel - 17) * 2, 255, &result);
      } else {
        composeRGBPixel((pixel - 145) * 2, 255, 255, &result);
      }
      col_data[x] = result;
    }
  }
  auto *win = new ScrollView("Projection", 0, 0, width, height, width, height);
  win->Draw(pixc, 0, 0);
  win->Update();
  pixc.destroy();
}