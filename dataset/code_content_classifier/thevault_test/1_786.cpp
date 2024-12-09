OrbPatterns(int sz, unsigned int normalized_step_size) :
    normalized_step_(normalized_step_size)
  {
    relative_patterns_.resize(kNumAngles);
    for (int i = 0; i < kNumAngles; i++)
      generateRelativePattern(i, sz, relative_patterns_[i]);
  }