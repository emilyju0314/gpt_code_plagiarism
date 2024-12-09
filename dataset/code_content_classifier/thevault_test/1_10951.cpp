void Network::ClearWindow(bool tess_coords, const char *window_name, int width, int height,
                          ScrollView **window) {
  if (*window == nullptr) {
    int min_size = std::min(width, height);
    if (min_size < kMinWinSize) {
      if (min_size < 1) {
        min_size = 1;
      }
      width = width * kMinWinSize / min_size;
      height = height * kMinWinSize / min_size;
    }
    width += kXWinFrameSize;
    height += kYWinFrameSize;
    if (width > kMaxWinSize) {
      width = kMaxWinSize;
    }
    if (height > kMaxWinSize) {
      height = kMaxWinSize;
    }
    *window = new ScrollView(window_name, 80, 100, width, height, width, height, tess_coords);
    tprintf("Created window %s of size %d, %d\n", window_name, width, height);
  } else {
    (*window)->Clear();
  }
}