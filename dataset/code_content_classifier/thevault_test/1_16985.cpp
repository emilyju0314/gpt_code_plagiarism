TEST_F(ThreadPoolJobTaskSourceTest, RunJoinTaskWorkerCount) {
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

  EXPECT_TRUE(task_source->WillJoin());
  // Once the worker_task runs, |worker_count| should drop to 0 and the job
  // should finish.
  EXPECT_FALSE(task_source->RunJoinTask());
  EXPECT_EQ(0U, max_concurrency);
}