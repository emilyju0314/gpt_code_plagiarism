bool Texture::loadImage(const std::vector<std::string> &urls,
                        std::vector<uint8_t *> *pixels) {
  stbi_set_flip_vertically_on_load(mFlip);
  for (auto filename : urls) {
    uint8_t *pixel = stbi_load(filename.c_str(), &mWidth, &mHeight, 0, 4);
    if (pixel == 0) {
      std::cout << stderr << "Couldn't open input file" << filename
                << std::endl;
      return false;
    }
    pixels->push_back(pixel);
  }
  return true;
}