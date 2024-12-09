TEST_F(ThreadPoolJobTaskSourceTest, NotifyConcurrencyIncrease) {
  auto job_task = base::MakeRefCounted<test::MockJobTask>(
      DoNothing(), /* num_tasks_to_run */ 1);
  scoped_refptr<JobTaskSource> task_source =
      job_task->GetJobTaskSource(FROM_HERE, {}, &pooled_task_runner_delegate_);

  auto registered_task_source_a =
      RegisteredTaskSource::CreateForTesting(task_source);
  EXPECT_EQ(registered_task_source_a.WillRunTask(),
            TaskSource::RunStatus::kAllowedSaturated);
  auto task_a = registered_task_source_a.TakeTask();
  EXPECT_EQ(RegisteredTaskSource::CreateForTesting(task_source).WillRunTask(),
            TaskSource::RunStatus::kDisallowed);

  job_task->SetNumTasksToRun(2);
  EXPECT_CALL(pooled_task_runner_delegate_, EnqueueJobTaskSource(_)).Times(1);
  task_source->NotifyConcurrencyIncrease();

  auto registered_task_source_b =
      RegisteredTaskSource::CreateForTesting(task_source);
  // WillRunTask() should return a valid RunStatus because max concurrency was
  // increased to 2.
  EXPECT_EQ(registered_task_source_b.WillRunTask(),
            TaskSource::RunStatus::kAllowedSaturated);
  auto task_b = registered_task_source_b.TakeTask();
  EXPECT_EQ(RegisteredTaskSource::CreateForTesting(task_source).WillRunTask(),
            TaskSource::RunStatus::kDisallowed);

  std::move(task_a.task).Run();
  EXPECT_FALSE(registered_task_source_a.DidProcessTask());

  std::move(task_b.task).Run();
  EXPECT_FALSE(registered_task_source_b.DidProcessTask());
}