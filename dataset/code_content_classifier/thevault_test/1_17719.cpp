TEST(Random, MultinomialGoodCase) {
  OpTester test("Multinomial");

  const int64_t num_samples = 10;
  const float seed = 1618.f;
  const int batch_size = 2;
  const int num_classes = 3;

  const std::vector<int64_t> input_dims{batch_size, num_classes};
  std::vector<float> input(TensorShape(input_dims).Size());
  std::fill(input.begin(), input.end(), -10.f);
  test.AddInput<float>("X", input_dims, input);

  test.AddAttribute("sample_size", num_samples);
  test.AddAttribute("seed", seed);
  test.AddAttribute<int64_t>("dtype", TensorProto::INT64);

  const std::vector<int64_t> output_dims{batch_size, num_samples};
#ifdef _WIN32
  const std::vector<int64_t> expected_output{2, 0, 0, 2, 2, 2, 0, 2, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 2, 0};
#elif defined(__MACH__)
  const std::vector<int64_t> expected_output{1, 1, 2, 2, 0, 2, 2, 2, 0, 2, 1, 1, 2, 0, 2, 2, 0, 2, 1, 1};
#else
  const std::vector<int64_t> expected_output{2, 0, 0, 1, 0, 1, 2, 0, 1, 0, 0, 1, 1, 0, 1, 0, 2, 0, 2, 0};
#endif
  test.AddOutput<int64_t>("Y", output_dims, expected_output);

  test.Run();
}