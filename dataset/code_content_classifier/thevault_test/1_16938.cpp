TEST(RangesTest, DontClashWithPredicateFromInternalInvoke) {
  {
    int input[] = {0, 1, 2};
    ranges::any_of(input, internal::predicate);
  }
  {
    internal::TestPair input[] = {{1, 2}, {3, 4}};
    ranges::any_of(input, base::identity{}, &internal::TestPair::a);
  }
}