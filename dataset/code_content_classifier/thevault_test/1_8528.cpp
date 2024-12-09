TEST_F(SlaveTest, GetExecutorInfoForTaskWithContainer)
{
  TestContainerizer containerizer;
  StandaloneMasterDetector detector;

  MockSlave slave(CreateSlaveFlags(), &detector, &containerizer);

  // Launch a task with the command executor and ContainerInfo with
  // NetworkInfo.
  TaskInfo task;
  task.set_name("task");
  task.mutable_task_id()->set_value("1");
  task.mutable_slave_id()->set_value(
      "20141010-221431-251662764-60288-12345-0001");
  task.mutable_resources()->MergeFrom(
      Resources::parse("cpus:0.1;mem:32").get());

  CommandInfo command;
  command.set_shell(false);
  command.set_value("/bin/echo");
  command.add_arguments("/bin/echo");
  command.add_arguments("--author");

  task.mutable_command()->MergeFrom(command);

  ContainerInfo *container = task.mutable_container();
  container->set_type(ContainerInfo::MESOS);

  NetworkInfo *network = container->add_network_infos();
  network->set_ip_address("4.3.2.1");
  network->add_groups("public");

  FrameworkInfo frameworkInfo;
  frameworkInfo.mutable_id()->set_value(
      "20141010-221431-251662764-60288-12345-0000");
  const ExecutorInfo& executor = slave.getExecutorInfo(frameworkInfo, task);

  // Now assert that the executor has both the command and ContainerInfo
  EXPECT_TRUE(executor.command().shell());
  // CommandInfo.container is not included. In this test the ContainerInfo
  // must be included in Executor.container (copied from TaskInfo.container).
  EXPECT_TRUE(executor.has_container());

  EXPECT_EQ("4.3.2.1", executor.container().network_infos(0).ip_address());
  EXPECT_EQ(1, executor.container().network_infos(0).groups_size());
  EXPECT_EQ("public", executor.container().network_infos(0).groups(0));
}