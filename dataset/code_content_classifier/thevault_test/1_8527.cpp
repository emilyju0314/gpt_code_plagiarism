TEST_F(SlaveTest, GetExecutorInfo)
{
  TestContainerizer containerizer;
  StandaloneMasterDetector detector;

  MockSlave slave(CreateSlaveFlags(), &detector, &containerizer);

  FrameworkID frameworkId;
  frameworkId.set_value("20141010-221431-251662764-60288-32120-0000");

  FrameworkInfo frameworkInfo;
  frameworkInfo.mutable_id()->CopyFrom(frameworkId);

  // Launch a task with the command executor.
  TaskInfo task;
  task.set_name("task");
  task.mutable_task_id()->set_value("1");
  task.mutable_slave_id()->set_value(
      "20141010-221431-251662764-60288-32120-0001");
  task.mutable_resources()->MergeFrom(
      Resources::parse("cpus:0.1;mem:32").get());

  CommandInfo command;
  command.set_shell(false);
  command.set_value("/bin/echo");
  command.add_arguments("/bin/echo");
  command.add_arguments("--author");

  task.mutable_command()->MergeFrom(command);

  const ExecutorInfo& executor = slave.getExecutorInfo(frameworkInfo, task);

  // Now assert that it actually is running mesos-executor without any
  // bleedover from the command we intend on running.
  EXPECT_TRUE(executor.command().shell());
  EXPECT_EQ(0, executor.command().arguments_size());
  EXPECT_NE(string::npos, executor.command().value().find("mesos-executor"));
}