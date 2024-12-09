TEST_F(ImportantFileWriterCleanerTest, StartTwice) {
  StartCleaner();
  ImportantFileWriterCleaner::AddDirectory(dir_1());
  task_environment_.RunUntilIdle();

  // Recreate the old file that was just cleaned.
  ASSERT_NO_FATAL_FAILURE(CreateOldFile(dir_1_file_old()));

  // Start again and make sure it wasn't cleaned again.
  ImportantFileWriterCleaner::GetInstance().Start();
  task_environment_.RunUntilIdle();

  EXPECT_TRUE(PathExists(dir_1_file_old()));
  histogram_tester_.ExpectUniqueSample("Windows.TmpFileDeleter.SuccessCount", 1,
                                       1);
  histogram_tester_.ExpectUniqueSample("Windows.TmpFileDeleter.FailCount", 0,
                                       1);
}