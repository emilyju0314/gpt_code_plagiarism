TEST(find_first_of, ExampleOne) {
    const std::vector<char> v{'1', '2', 'w', 'o', 'r', 'd', '3', '3'};
    const std::vector<char> sequence = {'w', 'r', 'd'};
    const auto iterator = std::find_first_of(v.cbegin(), v.cend(), sequence.cbegin(), sequence.cend());
    EXPECT_EQ(*iterator, 'w');
    EXPECT_EQ(iterator - v.cbegin(), 2);
}