TEST_F(StringFuncTest, Strip_ValidInputExtraEndingPathSeparators_Success)
    {
        AZStd::string       samplePath = "F:\\w s 1\\dev\\/";
        AZStd::string       expectedResult = "F:\\w s 1\\dev";
        const char*         stripCharacters = AZ_CORRECT_FILESYSTEM_SEPARATOR_STRING  AZ_WRONG_FILESYSTEM_SEPARATOR_STRING;

        AZ::StringFunc::Strip(samplePath, stripCharacters, false, false, true);

        ASSERT_TRUE(samplePath == expectedResult);
    }