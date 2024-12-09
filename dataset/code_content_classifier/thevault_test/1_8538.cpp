TEST_F(SlaveTest, KillTaskBetweenRunTaskParts)
{
  Try<Owned<cluster::Master>> master = StartMaster();
  ASSERT_SOME(master);

  MockExecutor exec(DEFAULT_EXECUTOR_ID);
  TestContainerizer containerizer(&exec);

  StandaloneMasterDetector detector(master.get()->pid);

  MockSlave slave(CreateSlaveFlags(), &detector, &containerizer);
  spawn(slave);

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

  TaskInfo task;
  task.set_name("");
  task.mutable_task_id()->set_value("1");
  task.mutable_slave_id()->MergeFrom(offers.get()[0].slave_id());
  task.mutable_resources()->MergeFrom(offers.get()[0].resources());
  task.mutable_executor()->MergeFrom(DEFAULT_EXECUTOR_INFO);

  EXPECT_CALL(exec, registered(_, _, _, _))
    .Times(0);

  EXPECT_CALL(exec, launchTask(_, _))
    .Times(0);

  EXPECT_CALL(exec, shutdown(_))
    .Times(0);

  Future<TaskStatus> status;
  EXPECT_CALL(sched, statusUpdate(&driver, _))
    .WillRepeatedly(FutureArg<1>(&status));

  EXPECT_CALL(slave, runTask(_, _, _, _, _))
    .WillOnce(Invoke(&slave, &MockSlave::unmocked_runTask));

  // Saved arguments from Slave::_runTask().
  Future<bool> future;
  FrameworkInfo frameworkInfo;

  // Skip what Slave::_runTask() normally does, save its arguments for
  // later, tie reaching the critical moment when to kill the task to
  // a future.
  Future<Nothing> _runTask;
  EXPECT_CALL(slave, _runTask(_, _, _))
    .WillOnce(DoAll(FutureSatisfy(&_runTask),
                    SaveArg<0>(&future),
                    SaveArg<1>(&frameworkInfo)));

  driver.launchTasks(offers.get()[0].id(), {task});

  AWAIT_READY(_runTask);

  // Since this is the only task ever for this framework, the
  // framework should get removed in Slave::killTask().
  // Thus we can observe that this happens before Shutdown().
  Future<Nothing> removeFramework;
  EXPECT_CALL(slave, removeFramework(_))
    .WillOnce(DoAll(Invoke(&slave, &MockSlave::unmocked_removeFramework),
                    FutureSatisfy(&removeFramework)));

  Future<Nothing> killTask;
  EXPECT_CALL(slave, killTask(_, _, _))
    .WillOnce(DoAll(Invoke(&slave, &MockSlave::unmocked_killTask),
                    FutureSatisfy(&killTask)));

  driver.killTask(task.task_id());

  AWAIT_READY(killTask);
  slave.unmocked__runTask(future, frameworkInfo, task);

  AWAIT_READY(removeFramework);

  AWAIT_READY(status);
  EXPECT_EQ(TASK_KILLED, status.get().state());

  driver.stop();
  driver.join();

  terminate(slave);
  wait(slave);
}