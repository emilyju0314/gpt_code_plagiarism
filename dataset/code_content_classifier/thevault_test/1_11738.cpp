inline float filter_catmullrom(float x) {
      x = (float)fabs(x);
      if (x < 1.0f) return 1 - x * x * (2.5f - 1.5f * x);
      if (x < 2.0f) return 2 - x * (4 + x * (0.5f * x - 2.5f));
      return 0.0f;
    }