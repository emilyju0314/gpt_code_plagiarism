TEST_F(ThreadPoolJobTaskSourceTest, ShouldYield) {
  auto job_task = base::MakeRefCounted<test::MockJobTask>(
      BindLambdaForTesting([](JobDelegate* delegate) {
        // As set up below, the mock will return false once and true the second
        // time.
        EXPECT_FALSE(delegate->ShouldYield());
        EXPECT_TRUE(delegate->ShouldYield());
      }),
      /* num_tasks_to_run */ 1);
  scoped_refptr<JobTaskSource> task_source =
      job_task->GetJobTaskSource(FROM_HERE, {}, &pooled_task_runner_delegate_);

  auto registered_task_source =
      RegisteredTaskSource::CreateForTesting(task_source);
  ASSERT_EQ(registered_task_source.WillRunTask(),
            TaskSource::RunStatus::kAllowedSaturated);

  auto task = registered_task_source.TakeTask();

  EXPECT_CALL(pooled_task_runner_delegate_, ShouldYield(_))
      .Times(2)
      .WillOnce(Return(false))
      .WillOnce(Return(true));

  std::move(task.task).Run();
  EXPECT_FALSE(registered_task_source.DidProcessTask());
}