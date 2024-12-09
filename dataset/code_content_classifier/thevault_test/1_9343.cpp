void Texture::DestoryImageData(std::vector<uint8_t *> &pixelVec) {
  for (auto &pixels : pixelVec) {
    free(pixels);
    pixels = nullptr;
  }
}