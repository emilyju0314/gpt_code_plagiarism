TEST (getRange, singleRange) {
    string testString = "[ 1 11 ]";
    vector<uint32_t> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    istringstream iss(testString);
    auto result = getRange(iss, IN);
    EXPECT_EQ(result, expected);
}