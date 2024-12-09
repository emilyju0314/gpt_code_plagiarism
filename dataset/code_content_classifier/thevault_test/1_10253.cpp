TEST (getRange, threeRangeOperands) {
    string testString = "3 [ 5 7 9 ] 12";
    istringstream iss(testString);

    try {
        auto result = getRange(iss, IN);
        FAIL() << "Expected Parsing Exception!";
    } catch (ParsingException e) {
        EXPECT_EQ(e.what(), "Parsing Exception!");
    } catch (exception e) {
        FAIL() << "Expected Parsing Exception, but got " << e.what();
    }
}