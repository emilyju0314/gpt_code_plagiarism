TEST_F(ImportantFileWriterCleanerTest, StartAddFromOtherThread) {
  StartCleaner();

  // Add from the ThreadPool and wait for it to finish.
  TestWaitableEvent waitable_event;
  ThreadPool::PostTask(FROM_HERE, BindLambdaForTesting([&]() {
                         ImportantFileWriterCleaner::AddDirectory(dir_1());
                         waitable_event.Signal();
                       }));
  waitable_event.Wait();

  // Allow the cleaner to run.
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