TEST(merge, ExampleOne) {
    std::vector<int> v1{0, 1, 2, 3, 3, 4, 5};
    std::vector<int> v2{0, 2, 3, 4, 4, 5};
    std::vector<int> destination;
    destination.reserve(v1.size() + v2.size());
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(destination));

    const std::vector<int> merged{0,0,1,2,2,3,3,3,4,4,4,5,5};
    EXPECT_EQ(destination, merged);
}