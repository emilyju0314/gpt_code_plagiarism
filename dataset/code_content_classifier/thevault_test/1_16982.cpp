TEST_F(ThreadPoolJobTaskSourceTest, RunTasksInParallel) {
  auto job_task = base::MakeRefCounted<test::MockJobTask>(
      DoNothing(), /* num_tasks_to_run */ 2);
  scoped_refptr<JobTaskSource> task_source =
      job_task->GetJobTaskSource(FROM_HERE, {}, &pooled_task_runner_delegate_);

  auto registered_task_source_a =
      RegisteredTaskSource::CreateForTesting(task_source);
  EXPECT_EQ(registered_task_source_a.WillRunTask(),
            TaskSource::RunStatus::kAllowedNotSaturated);
  EXPECT_EQ(1U, task_source->GetWorkerCount());
  EXPECT_EQ(1U, task_source->GetSortKey().worker_count());
  auto task_a = registered_task_source_a.TakeTask();

  auto registered_task_source_b =
      RegisteredTaskSource::CreateForTesting(task_source);
  EXPECT_EQ(registered_task_source_b.WillRunTask(),
            TaskSource::RunStatus::kAllowedSaturated);
  EXPECT_EQ(2U, task_source->GetWorkerCount());
  EXPECT_EQ(2U, task_source->GetSortKey().worker_count());
  auto task_b = registered_task_source_b.TakeTask();

  // WillRunTask() should return a null RunStatus once the max concurrency is
  // reached.
  EXPECT_EQ(RegisteredTaskSource::CreateForTesting(task_source).WillRunTask(),
            TaskSource::RunStatus::kDisallowed);

  std::move(task_a.task).Run();
  // Adding a task before closing the first run operation should cause the task
  // source to re-enqueue.
  job_task->SetNumTasksToRun(2);
  EXPECT_TRUE(registered_task_source_a.DidProcessTask());
  EXPECT_EQ(1U, task_source->GetSortKey().worker_count());

  std::move(task_b.task).Run();
  EXPECT_TRUE(registered_task_source_b.DidProcessTask());
  EXPECT_EQ(0U, task_source->GetSortKey().worker_count());

  EXPECT_EQ(0U, task_source->GetWorkerCount());

  auto registered_task_source_c =
      RegisteredTaskSource::CreateForTesting(task_source);
  EXPECT_EQ(registered_task_source_c.WillRunTask(),
            TaskSource::RunStatus::kAllowedSaturated);
  auto task_c = registered_task_source_c.TakeTask();

  std::move(task_c.task).Run();
  EXPECT_FALSE(registered_task_source_c.DidProcessTask());
}