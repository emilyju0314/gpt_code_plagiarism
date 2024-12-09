TEST_F(ImportantFileWriterCleanerTest, StopWhileRunning) {
  ImportantFileWriterCleaner::GetInstance().Initialize();

  // Create a great many old files in dir1.
  for (int i = 0; i < 100; ++i) {
    FilePath path;
    CreateOldFileInDir(dir_1(), path);
  }

  ImportantFileWriterCleaner::AddDirectory(dir_1());
  StartCleaner();

  // It's possible that the background task will quickly delete all 100 files.
  // In all likelihood, though, the stop flag will be read and processed before
  // then. Either case is a success.
  StopCleaner();
  task_environment_.RunUntilIdle();

  // Expect a single sample indicating that one or more files were deleted.
  histogram_tester_.ExpectTotalCount("Windows.TmpFileDeleter.SuccessCount", 1);
}