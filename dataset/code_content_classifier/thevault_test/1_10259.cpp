TEST (removeComments, oneCommentMark) {
    string testString = "02857sjfh#58048371";
    string result = removeComments(testString);
    EXPECT_EQ(result, "02857sjfh");
}