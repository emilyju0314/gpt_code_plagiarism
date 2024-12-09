TEST_F(ImportantFileWriterCleanerTest, AddStartAdd) {
  ImportantFileWriterCleaner::GetInstance().Initialize();
  ImportantFileWriterCleaner::AddDirectory(dir_1());
  StartCleaner();
  ImportantFileWriterCleaner::AddDirectory(dir_2());
  task_environment_.RunUntilIdle();

  // The old file should have been cleaned from both added dirs.
  EXPECT_TRUE(PathExists(dir_1_file_new()));
  EXPECT_FALSE(PathExists(dir_1_file_old()));
  EXPECT_TRUE(PathExists(dir_1_file_other()));
  EXPECT_TRUE(PathExists(dir_2_file_new()));
  EXPECT_FALSE(PathExists(dir_2_file_old()));
  EXPECT_TRUE(PathExists(dir_2_file_other()));

  // There should be 2 success and 2 failure samples (one for each dir).
  histogram_tester_.ExpectUniqueSample("Windows.TmpFileDeleter.SuccessCount", 1,
                                       2);
  histogram_tester_.ExpectUniqueSample("Windows.TmpFileDeleter.FailCount", 0,
                                       2);
}