TEST_F(ImportantFileWriterCleanerTest, AddStart) {
  ImportantFileWriterCleaner::GetInstance().Initialize();
  ImportantFileWriterCleaner::AddDirectory(dir_1());
  StartCleaner();
  task_environment_.RunUntilIdle();

  // The old file should have been cleaned from the added dir.
  EXPECT_TRUE(PathExists(dir_1_file_new()));
  EXPECT_FALSE(PathExists(dir_1_file_old()));
  EXPECT_TRUE(PathExists(dir_1_file_other()));
  EXPECT_TRUE(PathExists(dir_2_file_new()));
  EXPECT_TRUE(PathExists(dir_2_file_old()));
  EXPECT_TRUE(PathExists(dir_2_file_other()));

  // There should be 1 success and 0 failure logged for the one dir.
  histogram_tester_.ExpectUniqueSample("Windows.TmpFileDeleter.SuccessCount", 1,
                                       1);
  histogram_tester_.ExpectUniqueSample("Windows.TmpFileDeleter.FailCount", 0,
                                       1);
}