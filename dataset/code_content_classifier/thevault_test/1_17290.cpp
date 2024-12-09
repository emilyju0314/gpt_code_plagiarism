TEST(fill, ExampleOne) {
    std::vector<char> v{'a', 'b', 'c', 'd'};
    std::fill(v.begin(), v.end(), 'z');

    std::vector<char> new_v{'z', 'z', 'z', 'z'};
    EXPECT_EQ(v, new_v);
}