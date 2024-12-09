TEST(TransposeOpTest, ThreeDim) {
  std::vector<int64_t> input_shape({4, 2, 3});
  std::vector<float> input_vals = {
      1.0f, 2.0f, 3.0f,
      4.0f, 5.0f, 6.0f,

      1.1f, 2.1f, 3.1f,
      4.1f, 5.1f, 6.1f,

      1.2f, 2.2f, 3.2f,
      4.2f, 5.2f, 6.2f,

      1.3f, 2.3f, 3.3f,
      4.3f, 5.3f, 6.3f};

  std::vector<int64_t> perm = {0, 2, 1};
  std::vector<int64_t> expected_shape({4, 3, 2});
  auto expected_vals = {
      1.0f,
      4.0f,
      2.0f,
      5.0f,
      3.0f,
      6.0f,

      1.1f,
      4.1f,
      2.1f,
      5.1f,
      3.1f,
      6.1f,

      1.2f,
      4.2f,
      2.2f,
      5.2f,
      3.2f,
      6.2f,

      1.3f,
      4.3f,
      2.3f,
      5.3f,
      3.3f,
      6.3f,

  };

  TransposeTest(input_shape, input_vals, &perm, expected_shape, expected_vals);
}