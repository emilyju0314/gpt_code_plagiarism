vector<float> load_imagef_from_memory(const string& filename, const byte* data,
                                        int length, int& width, int& height, int& ncomp) {
    auto pixels =
        stbi_loadf_from_memory(data, length, &width, &height, &ncomp, 0);
    if (!pixels) return {};
    auto ret = vector<float>(pixels, pixels + width * height * ncomp);
    free(pixels);
    return ret;
  }