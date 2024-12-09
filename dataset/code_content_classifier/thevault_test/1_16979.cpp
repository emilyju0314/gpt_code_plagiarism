TEST_F(ThreadPoolJobTaskSourceTest, RunTasks) {
  auto job_task = base::MakeRefCounted<test::MockJobTask>(
      DoNothing(), /* num_tasks_to_run */ 2);
  scoped_refptr<JobTaskSource> task_source =
      job_task->GetJobTaskSource(FROM_HERE, {}, &pooled_task_runner_delegate_);
  auto registered_task_source =
      RegisteredTaskSource::CreateForTesting(task_source);

  EXPECT_EQ(2U, task_source->GetRemainingConcurrency());
  {
    EXPECT_EQ(registered_task_source.WillRunTask(),
              TaskSource::RunStatus::kAllowedNotSaturated);
    EXPECT_EQ(1U, task_source->GetWorkerCount());

    auto task = registered_task_source.TakeTask();
    std::move(task.task).Run();
    EXPECT_TRUE(registered_task_source.DidProcessTask());
    EXPECT_EQ(0U, task_source->GetWorkerCount());
  }
  {
    EXPECT_EQ(registered_task_source.WillRunTask(),
              TaskSource::RunStatus::kAllowedSaturated);
    EXPECT_EQ(1U, task_source->GetWorkerCount());

    // An attempt to run an additional task is not allowed.
    EXPECT_EQ(RegisteredTaskSource::CreateForTesting(task_source).WillRunTask(),
              TaskSource::RunStatus::kDisallowed);
    EXPECT_EQ(0U, task_source->GetRemainingConcurrency());
    auto task = registered_task_source.TakeTask();
    EXPECT_EQ(RegisteredTaskSource::CreateForTesting(task_source).WillRunTask(),
              TaskSource::RunStatus::kDisallowed);

    std::move(task.task).Run();
    EXPECT_EQ(0U, task_source->GetRemainingConcurrency());
    EXPECT_TRUE(task_source->IsActive());
    // Returns false because the task source is out of tasks.
    EXPECT_FALSE(registered_task_source.DidProcessTask());
    EXPECT_EQ(0U, task_source->GetWorkerCount());
    EXPECT_FALSE(task_source->IsActive());
  }
}