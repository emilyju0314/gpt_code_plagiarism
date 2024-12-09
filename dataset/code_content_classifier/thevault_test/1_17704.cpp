TEST(SplitOperatorTest, SplitAttributeSumTooSmall) {
  const int64_t axis = 0;
  std::vector<ShapeAndData> outputs;

  // input shape and data
  ShapeAndData input = {{4, 2},  // shape
                        {1.f, 2.f,
                         3.f, 4.f,
                         5.f, 6.f,
                         7.f, 8.f}};

  std::vector<int64_t> splits{1, 2};  // should sum to 4

  outputs.push_back({{1, 2}, {1.f, 2.f}});
  outputs.push_back({{2, 2}, {3.f, 4.f, 5.f, 6.f}});

  RunTest(axis, splits, input, outputs, true, "Cannot split using values in 'split' attribute");
}