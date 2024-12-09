TEST_P(PathHashCompareFixture, PathsWhichCompareEqual_HashesToSameValue_Succeeds)
    {
        auto&& [testPath1, compareMatcher, hashMatcher] = GetParam();

        // Compare path using parameterized Matcher
        EXPECT_THAT(testPath1, compareMatcher);
        // Compare hash using parameterized Matcher
        const size_t testPath1Hash = AZStd::hash<AZ::IO::PathView>{}(testPath1);
AZ_PUSH_DISABLE_WARNING(4296, "-Wunknown-warning-option")
        EXPECT_THAT(testPath1Hash, hashMatcher);
AZ_POP_DISABLE_WARNING
    }