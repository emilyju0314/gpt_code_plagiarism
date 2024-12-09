TEST(reverse, ExampleOne) {
    std::vector<int> v{1,2,3,4,5};
    std::reverse(v.begin(), v.end());

    const std::vector<int> reversed_v{5,4,3,2,1};
    EXPECT_EQ(v, reversed_v);
}