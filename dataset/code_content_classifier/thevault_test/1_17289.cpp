TEST(copy, ExampleOne) {
    const std::vector<int> from{1,2,3,4,5};
    std::vector<int> to;
    to.reserve(from.size());
    std::copy(from.cbegin(), from.cend(), std::back_inserter(to));
    EXPECT_EQ(from, to);
}