inline float filter_cubic(float x) {
      x = (float)fabs(x);
      if (x < 1.0f) return (4 + x * x * (3 * x - 6)) / 6;
      if (x < 2.0f) return (8 + x * (-12 + x * (6 - x))) / 6;
      return 0.0f;
    }