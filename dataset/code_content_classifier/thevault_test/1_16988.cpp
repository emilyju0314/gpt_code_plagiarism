TEST_F(ThreadPoolJobTaskSourceTest, RunJoinTaskInParallel) {
  auto job_task = base::MakeRefCounted<test::MockJobTask>(
      DoNothing(), /* num_tasks_to_run */ 2);
  scoped_refptr<JobTaskSource> task_source =
      job_task->GetJobTaskSource(FROM_HERE, {}, &pooled_task_runner_delegate_);

  auto registered_task_source =
      RegisteredTaskSource::CreateForTesting(task_source);
  EXPECT_EQ(registered_task_source.WillRunTask(),
            TaskSource::RunStatus::kAllowedNotSaturated);
  auto worker_task = registered_task_source.TakeTask();

  EXPECT_TRUE(task_source->WillJoin());
  EXPECT_TRUE(task_source->IsActive());

  std::move(worker_task.task).Run();
  EXPECT_FALSE(registered_task_source.DidProcessTask());

  EXPECT_FALSE(task_source->RunJoinTask());
  EXPECT_FALSE(task_source->IsActive());
}