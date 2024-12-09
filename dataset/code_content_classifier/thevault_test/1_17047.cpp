TEST_F(ImportantFileWriterCleanerTest, AddTwice) {
  StartCleaner();
  ImportantFileWriterCleaner::AddDirectory(dir_1());
  task_environment_.RunUntilIdle();

  // Recreate the old file that was just cleaned.
  ASSERT_NO_FATAL_FAILURE(CreateOldFile(dir_1_file_old()));

  // Add the directory again and make sure nothing else is cleaned.
  ImportantFileWriterCleaner::AddDirectory(dir_1());
  task_environment_.RunUntilIdle();

  EXPECT_TRUE(PathExists(dir_1_file_old()));
  histogram_tester_.ExpectUniqueSample("Windows.TmpFileDeleter.SuccessCount", 1,
                                       1);
  histogram_tester_.ExpectUniqueSample("Windows.TmpFileDeleter.FailCount", 0,
                                       1);
}