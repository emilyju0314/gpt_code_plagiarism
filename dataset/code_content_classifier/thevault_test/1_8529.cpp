TEST_F(SlaveTest, LaunchTaskInfoWithContainerInfo)
{
  Try<Owned<cluster::Master>> master = StartMaster();
  ASSERT_SOME(master);

  // Need flags for 'executor_registration_timeout'.
  slave::Flags flags = CreateSlaveFlags();
  flags.isolation = "posix/cpu,posix/mem";

  Fetcher fetcher;

  Try<MesosContainerizer*> _containerizer =
    MesosContainerizer::create(flags, false, &fetcher);

  CHECK_SOME(_containerizer);
  Owned<MesosContainerizer> containerizer(_containerizer.get());

  StandaloneMasterDetector detector;
  MockSlave slave(flags, &detector, containerizer.get());

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

  ContainerID containerId;
  containerId.set_value(UUID::random().toString());
  ContainerInfo *container = task.mutable_container();
  container->set_type(ContainerInfo::MESOS);

  NetworkInfo *network = container->add_network_infos();
  network->set_ip_address("4.3.2.1");
  network->add_groups("public");

  FrameworkInfo frameworkInfo;
  frameworkInfo.mutable_id()->set_value(
      "20141010-221431-251662764-60288-12345-0000");
  const ExecutorInfo& executor = slave.getExecutorInfo(frameworkInfo, task);

  SlaveID slaveID;
  slaveID.set_value(UUID::random().toString());
  Future<bool> launch = containerizer->launch(
      containerId,
      task,
      executor,
      "/tmp",
      "test",
      slaveID,
      slave.self(),
      false);
  AWAIT_READY(launch);

  // TODO(spikecurtis): With agent capabilities (MESOS-3362), the
  // Containerizer should fail this request since none of the listed
  // isolators can handle NetworkInfo, which implies
  // IP-per-container.
  EXPECT_TRUE(launch.get());

  // Wait for the container to terminate before shutting down.
  AWAIT_READY(containerizer->wait(containerId));
}