TEST_F(ThreadPoolJobTaskSourceTest, MaxConcurrencyStagnateIfShouldYield) {
  scoped_refptr<JobTaskSource> task_source =
      base::MakeRefCounted<JobTaskSource>(
          FROM_HERE, TaskTraits(), BindRepeating([](JobDelegate* delegate) {
            // As set up below, the mock will return true once.
            ASSERT_TRUE(delegate->ShouldYield());
          }),
          BindRepeating([](size_t /*worker_count*/) -> size_t {
            return 1;  // max concurrency is always 1.
          }),
          &pooled_task_runner_delegate_);

  EXPECT_CALL(pooled_task_runner_delegate_, ShouldYield(_))
      .WillOnce(Return(true));

  auto registered_task_source =
      RegisteredTaskSource::CreateForTesting(task_source);
  ASSERT_EQ(registered_task_source.WillRunTask(),
            TaskSource::RunStatus::kAllowedSaturated);
  auto task = registered_task_source.TakeTask();

  // Running the task should not fail even though max concurrency remained at 1,
  // since ShouldYield() returned true.
  std::move(task.task).Run();
  registered_task_source.DidProcessTask();
}