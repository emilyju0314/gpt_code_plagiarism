TEST (getRange, twoIDsRange) {
    string testString = "[ 3928 3929 ]";
    vector<uint32_t> expected = {3928, 3929};

    istringstream iss(testString);
    auto result = getRange(iss, IN);
    EXPECT_EQ(result, expected);
}