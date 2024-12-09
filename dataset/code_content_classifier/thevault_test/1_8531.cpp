TEST_F(SlaveTest, DISABLED_ROOT_RunTaskWithCommandInfoWithUser)
{
  // TODO(nnielsen): Introduce STOUT abstraction for user verification
  // instead of flat getpwnam call.
  const string testUser = "nobody";
  if (::getpwnam(testUser.c_str()) == NULL) {
    LOG(WARNING) << "Cannot run ROOT_RunTaskWithCommandInfoWithUser test:"
                 << " user '" << testUser << "' is not present";
    return;
  }

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

  Owned<MasterDetector> detector = master.get()->createDetector();

  Try<Owned<cluster::Slave>> slave =
    StartSlave(detector.get(), containerizer.get());
  ASSERT_SOME(slave);

  MockScheduler sched;
  MesosSchedulerDriver driver(
      &sched, DEFAULT_FRAMEWORK_INFO, master.get()->pid, DEFAULT_CREDENTIAL);

  EXPECT_CALL(sched, registered(&driver, _, _))
    .Times(1);

  Future<TaskStatus> statusRunning;
  Future<TaskStatus> statusFinished;
  const string helper = getTestHelperPath("active-user-test-helper");

  Future<vector<Offer>> offers;
  EXPECT_CALL(sched, resourceOffers(&driver, _))
    .WillOnce(FutureArg<1>(&offers))
    .WillRepeatedly(Return()); // Ignore subsequent offers.

  driver.start();

  AWAIT_READY(offers);
  EXPECT_NE(0u, offers.get().size());

  // HACK: Launch a prepare task as root to prepare the binaries.
  // This task creates the lt-mesos-executor binary in the build dir.
  // Because the real task is run as a test user (nobody), it does not
  // have permission to create files in the build directory.
  TaskInfo prepareTask;
  prepareTask.set_name("prepare task");
  prepareTask.mutable_task_id()->set_value("1");
  prepareTask.mutable_slave_id()->CopyFrom(offers.get()[0].slave_id());
  prepareTask.mutable_resources()->CopyFrom(
      offers.get()[0].resources());

  Result<string> user = os::user();
  CHECK_SOME(user) << "Failed to get current user name"
                   << (user.isError() ? ": " + user.error() : "");
  // Current user should be root.
  EXPECT_EQ("root", user.get());

  // This prepare command executor will run as the current user
  // running the tests (root). After this command executor finishes,
  // we know that the lt-mesos-executor binary file exists.
  CommandInfo prepareCommand;
  prepareCommand.set_shell(false);
  prepareCommand.set_value(helper);
  prepareCommand.add_arguments(helper);
  prepareCommand.add_arguments(user.get());
  prepareTask.mutable_command()->CopyFrom(prepareCommand);

  EXPECT_CALL(sched, statusUpdate(&driver, _))
    .WillOnce(FutureArg<1>(&statusRunning))
    .WillOnce(FutureArg<1>(&statusFinished));

  driver.launchTasks(offers.get()[0].id(), {prepareTask});

  // Scheduler should first receive TASK_RUNNING followed by the
  // TASK_FINISHED from the executor.
  AWAIT_READY(statusRunning);
  EXPECT_EQ(TASK_RUNNING, statusRunning.get().state());
  EXPECT_EQ(TaskStatus::SOURCE_EXECUTOR, statusRunning.get().source());

  AWAIT_READY(statusFinished);
  EXPECT_EQ(TASK_FINISHED, statusFinished.get().state());
  EXPECT_EQ(TaskStatus::SOURCE_EXECUTOR, statusFinished.get().source());

  // Start to launch a task with different user.
  EXPECT_CALL(sched, resourceOffers(&driver, _))
    .WillOnce(FutureArg<1>(&offers))
    .WillRepeatedly(Return()); // Ignore subsequent offers.

  AWAIT_READY(offers);
  EXPECT_NE(0u, offers.get().size());

  // Launch a task with the command executor.
  TaskInfo task;
  task.set_name("");
  task.mutable_task_id()->set_value("2");
  task.mutable_slave_id()->CopyFrom(offers.get()[0].slave_id());
  task.mutable_resources()->CopyFrom(offers.get()[0].resources());

  CommandInfo command;
  command.set_user(testUser);
  command.set_shell(false);
  command.set_value(helper);
  command.add_arguments(helper);
  command.add_arguments(testUser);

  task.mutable_command()->CopyFrom(command);

  EXPECT_CALL(sched, statusUpdate(&driver, _))
    .WillOnce(FutureArg<1>(&statusRunning))
    .WillOnce(FutureArg<1>(&statusFinished));

  driver.launchTasks(offers.get()[0].id(), {task});

  // Scheduler should first receive TASK_RUNNING followed by the
  // TASK_FINISHED from the executor.
  AWAIT_READY(statusRunning);
  EXPECT_EQ(TASK_RUNNING, statusRunning.get().state());
  EXPECT_EQ(TaskStatus::SOURCE_EXECUTOR, statusRunning.get().source());

  AWAIT_READY(statusFinished);
  EXPECT_EQ(TASK_FINISHED, statusFinished.get().state());
  EXPECT_EQ(TaskStatus::SOURCE_EXECUTOR, statusFinished.get().source());

  driver.stop();
  driver.join();
}