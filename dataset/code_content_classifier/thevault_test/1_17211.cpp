TEST(CheckedContiguousIterator, OptimizedCopy) {
  using Iter = DisableDerefAndIncr<CheckedContiguousIterator<int>>;

  int arr_in[5] = {1, 2, 3, 4, 5};
  int arr_out[5];

  Iter in_begin(std::begin(arr_in), std::end(arr_in));
  Iter in_end(std::begin(arr_in), std::end(arr_in), std::end(arr_in));
  Iter out_begin(std::begin(arr_out), std::end(arr_out));
  Iter out_end = std::copy(in_begin, in_end, out_begin);
  EXPECT_EQ(out_end, out_begin + (in_end - in_begin));

  EXPECT_TRUE(std::equal(std::begin(arr_in), std::end(arr_in),
                         std::begin(arr_out), std::end(arr_out)));
}