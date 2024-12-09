TEST (isValidParsingString, wrongCircuit) {
    EXPECT_FALSE(isValidParsingString("abcd", IN));
    EXPECT_FALSE(isValidParsingString("abcd", OUT));
    EXPECT_FALSE(isValidParsingString("abcd", CIRC_IN));
    EXPECT_FALSE(isValidParsingString("abcd", CIRC_OUT));
}