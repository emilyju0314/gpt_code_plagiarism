void HistogramRect(Image src_pix, int channel, int left, int top, int width, int height,
                   int *histogram) {
  int num_channels = pixGetDepth(src_pix) / 8;
  channel = ClipToRange(channel, 0, num_channels - 1);
  int bottom = top + height;
  memset(histogram, 0, sizeof(*histogram) * kHistogramSize);
  int src_wpl = pixGetWpl(src_pix);
  l_uint32 *srcdata = pixGetData(src_pix);
  for (int y = top; y < bottom; ++y) {
    const l_uint32 *linedata = srcdata + y * src_wpl;
    for (int x = 0; x < width; ++x) {
      int pixel = GET_DATA_BYTE(linedata, (x + left) * num_channels + channel);
      ++histogram[pixel];
    }
  }
}