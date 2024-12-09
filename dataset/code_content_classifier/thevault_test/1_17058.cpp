std::vector<log_uniform_i32::param_type> GenParams() {
  using Param = log_uniform_i32::param_type;
  using Limits = std::numeric_limits<int32_t>;

  return std::vector<Param>{
      Param{0, 1, 2},
      Param{1, 1, 2},
      Param{0, 2, 2},
      Param{0, 3, 2},
      Param{0, 4, 2},
      Param{0, 9, 10},
      Param{0, 10, 10},
      Param{0, 11, 10},
      Param{1, 10, 10},
      Param{0, (1 << 8) - 1, 2},
      Param{0, (1 << 8), 2},
      Param{0, (1 << 30) - 1, 2},
      Param{-1000, 1000, 10},
      Param{0, Limits::max(), 2},
      Param{0, Limits::max(), 3},
      Param{0, Limits::max(), 10},
      Param{Limits::min(), 0},
      Param{Limits::min(), Limits::max(), 2},
  };
}