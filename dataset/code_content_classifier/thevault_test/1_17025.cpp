TEST_F(TimeZoneDataTest, CompareSystemRevisionWithExpected) {
  if (!base::PathExists(base::FilePath(kRevisionFilePath))) {
    LOG(INFO) << "Skipped test because tzdata config is not present";
    return;
  }

  // ResetIcu() ensures that time zone data is loaded from the default location.

  ASSERT_TRUE(InitializeICU());
  std::string expected;
  ASSERT_TRUE(
      base::ReadFileToString(base::FilePath(kRevisionFilePath), &expected));
  std::string actual;
  GetActualRevision(&actual);
  EXPECT_EQ(expected, actual);
}