TEST_F(ThreadPoolJobTaskSourceTest, CancelJoinTask) {
  auto job_task = base::MakeRefCounted<test::MockJobTask>(
      DoNothing(), /* num_tasks_to_run */ 2);
  scoped_refptr<JobTaskSource> task_source =
      job_task->GetJobTaskSource(FROM_HERE, {}, &pooled_task_runner_delegate_);

  task_source->Cancel();
  EXPECT_FALSE(task_source->WillJoin());
}