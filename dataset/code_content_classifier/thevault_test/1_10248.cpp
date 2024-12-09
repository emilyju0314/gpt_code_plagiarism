TEST (getRange, IDsAndRange) {
    string testString = "[ 1 6 ] 8 10 [ 12 17 ] 21 23 27";
    vector<uint32_t> expected = {1, 2, 3, 4, 5, 6, 8, 10, 12, 13, 14, 15, 16, 17, 21, 23, 27};

    istringstream iss(testString);
    auto result = getRange(iss, IN);
    EXPECT_EQ(result, expected);
}