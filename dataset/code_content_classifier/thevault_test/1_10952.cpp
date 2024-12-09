int Network::DisplayImage(Image pix, ScrollView *window) {
  int height = pixGetHeight(pix);
  window->Draw(pix, 0, 0);
  pix.destroy();
  return height;
}