TEST (removeComments, onlyCommentMark) {
    string testString = "#";
    string result = removeComments(testString);
    EXPECT_EQ(result, "");
}