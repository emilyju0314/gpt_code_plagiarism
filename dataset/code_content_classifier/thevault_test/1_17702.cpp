TEST(SplitOperatorTest, Axis1SplitMiddleDimensionEqually) {
  const int64_t axis = 1;
  std::vector<ShapeAndData> outputs;

  ShapeAndData input = CreateInput({2, 4, 4});

  outputs.push_back({{2, 2, 4},
                     {1.f, 2.f, 3.f, 4.f,
                      5.f, 6.f, 7.f, 8.f,

                      17.f, 18.f, 19.f, 20.f,
                      21.f, 22.f, 23.f, 24.f}});

  outputs.push_back({{2, 2, 4},
                     {9.f, 10.f, 11.f, 12.f,
                      13.f, 14.f, 15.f, 16.f,

                      25.f, 26.f, 27.f, 28.f,
                      29.f, 30.f, 31.f, 32.f}});

  RunTest(axis, {}, input, outputs);
}