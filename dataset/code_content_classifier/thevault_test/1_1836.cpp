TEST(ChunkedArrayIterator, StdFind) {
  auto chunked_array1 =
      ChunkedArrayFromJSON(int32(), {R"([5, 10])", R"([null])", R"([16])"});
  auto it_begin = Begin<Int32Type>(*chunked_array1);
  auto it_end = End<Int32Type>(*chunked_array1);

  auto it = std::find(it_begin, it_end, 10);
  ASSERT_EQ(it.index(), 1);
  it = std::find(it_begin, it_end, nullopt);
  ASSERT_EQ(it.index(), 2);
  it = std::find(it_begin, it_end, 20);
  ASSERT_EQ(it, it_end);
}