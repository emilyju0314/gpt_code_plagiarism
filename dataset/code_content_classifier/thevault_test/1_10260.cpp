TEST (removeComments, twoCommentMarks) {
    string testString = "0123456#7890#9621";
    string result = removeComments(testString);
    EXPECT_EQ(result, "0123456");
}