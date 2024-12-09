TEST (getRange, outAfterRange) {
    string testString = "1 [ 3 6 ] 9 out 99 [ 100 103 ]";
    vector<uint32_t> expected = {1, 3, 4, 5, 6, 9};

    istringstream iss(testString);
    auto result = getRange(iss, IN);
    EXPECT_EQ(result, expected);
}