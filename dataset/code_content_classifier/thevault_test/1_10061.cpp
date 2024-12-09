TEST_F(FileUtilsTest, DISABLED_ON_ANDROID(OutputPathFromUnchangedWorkingDir)) {
  std::string path = webrtc::test::OutputPath();
  std::string expected_end = "out";
  expected_end = kPathDelimiter + expected_end + kPathDelimiter;
  ASSERT_EQ(path.length() - expected_end.length(), path.find(expected_end));
}