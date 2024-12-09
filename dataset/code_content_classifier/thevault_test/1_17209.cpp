TEST(CheckedContiguousIterator, StaticComparisonOperators) {
  static constexpr int arr[] = {0};

  constexpr CheckedContiguousConstIterator<int> begin(arr, arr, arr + 1);
  constexpr CheckedContiguousConstIterator<int> end(arr, arr + 1, arr + 1);

  static_assert(begin == begin, "");
  static_assert(end == end, "");

  static_assert(begin != end, "");
  static_assert(end != begin, "");

  static_assert(begin < end, "");

  static_assert(begin <= begin, "");
  static_assert(begin <= end, "");
  static_assert(end <= end, "");

  static_assert(end > begin, "");

  static_assert(end >= end, "");
  static_assert(end >= begin, "");
  static_assert(begin >= begin, "");
}