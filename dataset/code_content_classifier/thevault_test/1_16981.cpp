TEST_F(ThreadPoolJobTaskSourceTest, Cancel) {
  auto job_task = base::MakeRefCounted<test::MockJobTask>(
      DoNothing(), /* num_tasks_to_run */ 3);
  scoped_refptr<JobTaskSource> task_source = job_task->GetJobTaskSource(
      FROM_HERE, {TaskPriority::BEST_EFFORT}, &pooled_task_runner_delegate_);

  auto registered_task_source_a =
      RegisteredTaskSource::CreateForTesting(task_source);
  EXPECT_EQ(registered_task_source_a.WillRunTask(),
            TaskSource::RunStatus::kAllowedNotSaturated);
  auto task_a = registered_task_source_a.TakeTask();

  auto registered_task_source_b =
      RegisteredTaskSource::CreateForTesting(task_source);
  EXPECT_EQ(registered_task_source_b.WillRunTask(),
            TaskSource::RunStatus::kAllowedNotSaturated);

  EXPECT_FALSE(task_source->ShouldYield());

  task_source->Cancel();
  EXPECT_TRUE(task_source->ShouldYield());

  // The task source shouldn't allow any further tasks after Cancel.
  EXPECT_EQ(RegisteredTaskSource::CreateForTesting(task_source).WillRunTask(),
            TaskSource::RunStatus::kDisallowed);

  // A task that was already acquired can still run.
  std::move(task_a.task).Run();
  registered_task_source_a.DidProcessTask();

  // A RegisteredTaskSource that's ready can also take and run a task.
  {
    auto task = registered_task_source_b.TakeTask();
    std::move(task.task).Run();
    registered_task_source_b.DidProcessTask();
  }
}