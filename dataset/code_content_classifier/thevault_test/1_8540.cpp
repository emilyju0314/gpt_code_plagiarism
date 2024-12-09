TEST_F(SlaveTest, TotalSlaveResourcesIncludedInUsage)
{
  Try<Owned<cluster::Master>> master = StartMaster();
  ASSERT_SOME(master);

  TestContainerizer containerizer;
  StandaloneMasterDetector detector(master.get()->pid);

  slave::Flags flags = CreateSlaveFlags();
  flags.resources = "cpus:2;mem:1024;disk:1024;ports:[31000-32000]";

  MockSlave slave(flags, &detector, &containerizer);
  spawn(slave);

  Clock::pause();

  // Wait for slave to be initialized.
  Clock::settle();

  // We expect that the slave will return ResourceUsage with
  // total resources reported.
  Future<ResourceUsage> usage = slave.usage();

  AWAIT_READY(usage);

  // Total resources should match the resources from flag.resources.
  EXPECT_EQ(Resources(usage.get().total()),
            Resources::parse(flags.resources.get()).get());

  terminate(slave);
  wait(slave);
}