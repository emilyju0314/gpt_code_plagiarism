Film(uint32_t _width, uint32_t _height, Real _width_length = 0.025,
       Real _height_length = 0.025)
      : width(_width),
        height(_height),
        width_length(_width_length),
        height_length(_height_length) {
    pixels = new Vec3[width * height];
  }