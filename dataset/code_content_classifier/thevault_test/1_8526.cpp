TEST_F(SlaveTest, CommandExecutorWithOverride)
{
  Try<Owned<cluster::Master>> master = StartMaster();
  ASSERT_SOME(master);

  TestContainerizer containerizer;

  Owned<MasterDetector> detector = master.get()->createDetector();
  Try<Owned<cluster::Slave>> slave = StartSlave(detector.get(), &containerizer);
  ASSERT_SOME(slave);

  MockScheduler sched;
  MesosSchedulerDriver driver(
      &sched, DEFAULT_FRAMEWORK_INFO, master.get()->pid, DEFAULT_CREDENTIAL);

  EXPECT_CALL(sched, registered(&driver, _, _))
    .Times(1);

  Future<vector<Offer>> offers;
  EXPECT_CALL(sched, resourceOffers(&driver, _))
    .WillOnce(FutureArg<1>(&offers))
    .WillRepeatedly(Return()); // Ignore subsequent offers.

  driver.start();

  AWAIT_READY(offers);
  EXPECT_NE(0u, offers.get().size());

  // Launch a task with the command executor.
  TaskInfo task;
  task.set_name("");
  task.mutable_task_id()->set_value("1");
  task.mutable_slave_id()->MergeFrom(offers.get()[0].slave_id());
  task.mutable_resources()->MergeFrom(offers.get()[0].resources());

  CommandInfo command;
  command.set_value("sleep 10");

  task.mutable_command()->MergeFrom(command);

  // Expect the launch and just assume it was sucessful since we'll be
  // launching the executor ourselves manually below.
  Future<Nothing> launch;
  EXPECT_CALL(containerizer, launch(_, _, _, _, _, _, _))
    .WillOnce(DoAll(FutureSatisfy(&launch),
                    Return(true)));

  // Expect wait after launch is called but don't return anything
  // until after we've finished everything below.
  Future<Nothing> wait;
  Promise<containerizer::Termination> promise;
  EXPECT_CALL(containerizer, wait(_))
    .WillOnce(DoAll(FutureSatisfy(&wait),
                    Return(promise.future())));

  driver.launchTasks(offers.get()[0].id(), {task});

  // Once we get the launch the mesos-executor with --override.
  AWAIT_READY(launch);

  // Set up fake environment for executor.
  map<string, string> environment = os::environment();
  environment["MESOS_SLAVE_PID"] = stringify(slave.get()->pid);
  environment["MESOS_SLAVE_ID"] = stringify(offers.get()[0].slave_id());
  environment["MESOS_FRAMEWORK_ID"] = stringify(offers.get()[0].framework_id());
  environment["MESOS_EXECUTOR_ID"] = stringify(task.task_id());
  environment["MESOS_DIRECTORY"] = "";

  // Create temporary file to store validation string. If command is
  // succesfully replaced, this file will end up containing the string
  // 'Hello World\n'. Otherwise, the original task command i.e.
  // 'sleep' will be called and the test will fail.
  Try<string> file = os::mktemp();
  ASSERT_SOME(file);

  string executorCommand =
    path::join(getLauncherDir(), "mesos-executor") +
    " --override -- /bin/sh -c 'echo hello world >" + file.get() + "'";

  // Expect two status updates, one for once the mesos-executor says
  // the task is running and one for after our overridden command
  // above finishes.
  Future<TaskStatus> statusRunning, statusFinished;
  EXPECT_CALL(sched, statusUpdate(_, _))
    .WillOnce(FutureArg<1>(&statusRunning))
    .WillOnce(FutureArg<1>(&statusFinished));

  Try<Subprocess> executor =
    subprocess(
        executorCommand,
        Subprocess::PIPE(),
        Subprocess::PIPE(),
        Subprocess::PIPE(),
        NO_SETSID,
        environment);

  ASSERT_SOME(executor);

  // Scheduler should first receive TASK_RUNNING followed by the
  // TASK_FINISHED from the executor.
  AWAIT_READY(statusRunning);
  ASSERT_EQ(TASK_RUNNING, statusRunning.get().state());
  EXPECT_EQ(TaskStatus::SOURCE_EXECUTOR, statusRunning.get().source());

  AWAIT_READY(statusFinished);
  ASSERT_EQ(TASK_FINISHED, statusFinished.get().state());
  EXPECT_EQ(TaskStatus::SOURCE_EXECUTOR, statusFinished.get().source());

  AWAIT_READY(wait);

  containerizer::Termination termination;
  termination.set_message("Killed executor");
  termination.set_status(0);
  promise.set(termination);

  driver.stop();
  driver.join();

  AWAIT_READY(executor.get().status());

  // Verify file contents.
  Try<string> validate = os::read(file.get());
  ASSERT_SOME(validate);

  EXPECT_EQ(validate.get(), "hello world\n");

  os::rm(file.get());
}