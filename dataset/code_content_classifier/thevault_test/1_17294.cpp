TEST(rotate, ExampleOne) {
    std::vector<int> v{1,2,3,4,5};

    // Element in the middle, v.begin() + 1
    // becomes first element.
    std::rotate(v.begin(), v.begin() + 1, v.end());

    const std::vector<int> rotated_v{2,3,4,5,1};
    EXPECT_EQ(v, rotated_v);
}