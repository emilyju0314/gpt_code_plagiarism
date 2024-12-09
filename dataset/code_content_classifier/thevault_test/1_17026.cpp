TEST_F(TimeZoneDataTest, TestLoadingTimeZoneDataFromKnownConfigs) {
  ASSERT_TRUE(base::DirectoryExists(base::FilePath(kTzDataDirPath)));
  SetIcuTimeZoneDataDirForTesting(kTzDataDirPath);

  EXPECT_TRUE(InitializeICU());
  std::string actual;
  GetActualRevision(&actual);
  EXPECT_EQ("2019a", actual) << "If ICU no longer supports this tzdata "
                                "version, tzdata version needs to be upgraded";
}