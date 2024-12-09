TEST_F(ThreadPoolJobTaskSourceTest, GetTaskId) {
  auto task_source = MakeRefCounted<JobTaskSource>(
      FROM_HERE, TaskTraits{}, BindRepeating([](JobDelegate* delegate) {
        // Confirm that task id 0 is reused on the second run.
        EXPECT_EQ(0U, delegate->GetTaskId());

        // Allow running the task again.
        delegate->NotifyConcurrencyIncrease();
      }),
      BindRepeating([](size_t /*worker_count*/) -> size_t { return 1; }),
      &pooled_task_runner_delegate_);

  auto registered_task_source =
      RegisteredTaskSource::CreateForTesting(task_source);

  // Run the worker_task twice.
  ASSERT_EQ(registered_task_source.WillRunTask(),
            TaskSource::RunStatus::kAllowedSaturated);
  auto task1 = registered_task_source.TakeTask();
  std::move(task1.task).Run();
  registered_task_source.DidProcessTask();

  ASSERT_EQ(registered_task_source.WillRunTask(),
            TaskSource::RunStatus::kAllowedSaturated);
  auto task2 = registered_task_source.TakeTask();
  std::move(task2.task).Run();
  registered_task_source.DidProcessTask();
}