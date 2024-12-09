TEST_F(ThreadPoolJobTaskSourceTest, RunTaskWorkerCount) {
  size_t max_concurrency = 1;
  scoped_refptr<JobTaskSource> task_source =
      base::MakeRefCounted<JobTaskSource>(
          FROM_HERE, TaskTraits(),
          BindLambdaForTesting(
              [&](JobDelegate* delegate) { --max_concurrency; }),
          BindLambdaForTesting([&](size_t worker_count) -> size_t {
            return max_concurrency + worker_count;
          }),
          &pooled_task_runner_delegate_);

  auto registered_task_source =
      RegisteredTaskSource::CreateForTesting(task_source);

  EXPECT_EQ(registered_task_source.WillRunTask(),
            TaskSource::RunStatus::kAllowedSaturated);
  auto task = registered_task_source.TakeTask();
  std::move(task.task).Run();
  // Once the worker_task runs, |worker_count| should drop to 0 and the job
  // should finish.
  EXPECT_FALSE(registered_task_source.DidProcessTask());
  EXPECT_EQ(0U, max_concurrency);
}