inline float filter_mitchell(float x) {
      x = (float)fabs(x);
      if (x < 1.0f) return (16 + x * x * (21 * x - 36)) / 18;
      if (x < 2.0f) return (32 + x * (-60 + x * (36 - 7 * x))) / 18;
      return 0.0f;
    }