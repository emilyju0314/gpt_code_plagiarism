TEST (isValidParsingString, range) {
    EXPECT_TRUE(isValidParsingString("[", CIRC_OUT));
    EXPECT_TRUE(isValidParsingString("]", CIRC_OUT));
    EXPECT_TRUE(isValidParsingString("7737982", CIRC_OUT));
}