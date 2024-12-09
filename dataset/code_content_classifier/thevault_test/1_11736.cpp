inline float filter_triangle(float x) {
      x = (float)fabs(x);
      if (x <= 1.0f) return 1 - x;
      return 0;
    }