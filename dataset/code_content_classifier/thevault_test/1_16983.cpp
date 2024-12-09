TEST_F(ThreadPoolJobTaskSourceTest, RunJoinTask) {
  auto job_task = base::MakeRefCounted<test::MockJobTask>(
      DoNothing(), /* num_tasks_to_run */ 2);
  scoped_refptr<JobTaskSource> task_source =
      job_task->GetJobTaskSource(FROM_HERE, {}, &pooled_task_runner_delegate_);

  EXPECT_TRUE(task_source->WillJoin());
  // Intentionally run |worker_task| twice to make sure RunJoinTask() calls
  // it again. This can happen in production if the joining thread spuriously
  // return and needs to run again.
  EXPECT_TRUE(task_source->RunJoinTask());
  EXPECT_FALSE(task_source->RunJoinTask());
}