vector<byte> load_image_from_memory(const string& filename, const byte* data,
                                      int length, int& width, int& height, int& ncomp) {
    auto pixels =
        stbi_load_from_memory(data, length, &width, &height, &ncomp, 0);
    if (!pixels) return {};
    auto ret = vector<byte>(pixels, pixels + width * height * ncomp);
    free(pixels);
    return ret;
  }