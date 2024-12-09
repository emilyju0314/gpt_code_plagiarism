TEST(search, ExampleOne) {
    // This is going to find the first sub-sequence inside a container,
    // and return an iterator to it.
    const std::vector<int> v{1,2,3,4,1,2,3,4,1,2,3,4};
    const std::vector<int> sequence{1,2,3,4};
    const auto sequence_iterator = std::search(v.cbegin(), v.cend(), sequence.cbegin(), sequence.cend());
    EXPECT_EQ(*sequence_iterator, 1);
    EXPECT_EQ(sequence_iterator - v.cbegin(), 0); // Iterator begins at last sub-sequence.
}