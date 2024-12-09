image4b make_noise_image(int resx, int resy, float scale, bool wrap) {
    auto wrap3i = (wrap) ? vec3i{resx, resy, 2} : zero3i;
    auto img = image4b(resx, resy);
    for (auto j = 0; j < resy; j++) {
      for (auto i = 0; i < resx; i++) {
        auto p = vec3f{i / (float)resx, j / (float)resy, 0.5f} * scale;
        auto g = perlin_noise(p, wrap3i);
        g = clamp(0.5f + 0.5f * g, 0.0f, 1.0f);
        img[{i, j}] = float_to_byte({g, g, g, 1});
      }
    }
    return img;
  }