TEST_F(ThreadPoolJobTaskSourceTest, Clear) {
  auto job_task = base::MakeRefCounted<test::MockJobTask>(
      DoNothing(), /* num_tasks_to_run */ 5);
  scoped_refptr<JobTaskSource> task_source =
      job_task->GetJobTaskSource(FROM_HERE, {}, &pooled_task_runner_delegate_);

  EXPECT_EQ(5U, task_source->GetRemainingConcurrency());
  auto registered_task_source_a =
      RegisteredTaskSource::CreateForTesting(task_source);
  EXPECT_EQ(registered_task_source_a.WillRunTask(),
            TaskSource::RunStatus::kAllowedNotSaturated);
  auto task_a = registered_task_source_a.TakeTask();

  auto registered_task_source_b =
      RegisteredTaskSource::CreateForTesting(task_source);
  EXPECT_EQ(registered_task_source_b.WillRunTask(),
            TaskSource::RunStatus::kAllowedNotSaturated);

  auto registered_task_source_c =
      RegisteredTaskSource::CreateForTesting(task_source);
  EXPECT_EQ(registered_task_source_c.WillRunTask(),
            TaskSource::RunStatus::kAllowedNotSaturated);

  auto registered_task_source_d =
      RegisteredTaskSource::CreateForTesting(task_source);
  EXPECT_EQ(registered_task_source_d.WillRunTask(),
            TaskSource::RunStatus::kAllowedNotSaturated);

  EXPECT_FALSE(task_source->ShouldYield());

  {
    EXPECT_EQ(1U, task_source->GetRemainingConcurrency());
    auto task = registered_task_source_c.Clear();
    std::move(task.task).Run();
    registered_task_source_c.DidProcessTask();
    EXPECT_EQ(0U, task_source->GetRemainingConcurrency());
  }
  // The task source shouldn't allow any further tasks after Clear.
  EXPECT_TRUE(task_source->ShouldYield());
  EXPECT_EQ(RegisteredTaskSource::CreateForTesting(task_source).WillRunTask(),
            TaskSource::RunStatus::kDisallowed);

  // Another outstanding RunStatus can still call Clear.
  {
    auto task = registered_task_source_d.Clear();
    std::move(task.task).Run();
    registered_task_source_d.DidProcessTask();
    EXPECT_EQ(0U, task_source->GetRemainingConcurrency());
  }

  // A task that was already acquired can still run.
  std::move(task_a.task).Run();
  registered_task_source_a.DidProcessTask();

  // A valid outstanding RunStatus can also take and run a task.
  {
    auto task = registered_task_source_b.TakeTask();
    std::move(task.task).Run();
    registered_task_source_b.DidProcessTask();
  }
}