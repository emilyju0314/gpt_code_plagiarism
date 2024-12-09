TEST_F(SlaveTest, CancelSlaveShutdown)
{
  // Start a master.
  auto slaveRemovalLimiter = std::make_shared<MockRateLimiter>();
  master::Flags masterFlags = CreateMasterFlags();

  Try<Owned<cluster::Master>> master =
    StartMaster(slaveRemovalLimiter, masterFlags);
  ASSERT_SOME(master);

  // Set these expectations up before we spawn the slave so that we
  // don't miss the first PING.
  Future<Message> ping = FUTURE_MESSAGE(
      Eq(PingSlaveMessage().GetTypeName()), _, _);

  // Drop all the PONGs to simulate health check timeout.
  DROP_PROTOBUFS(PongSlaveMessage(), _, _);

  // No shutdown should occur during the test!
  EXPECT_NO_FUTURE_PROTOBUFS(ShutdownMessage(), _, _);

  Future<SlaveRegisteredMessage> slaveRegisteredMessage =
    FUTURE_PROTOBUF(SlaveRegisteredMessage(), _, _);

  Owned<MasterDetector> detector = master.get()->createDetector();

  // Start a slave.
  Try<Owned<cluster::Slave>> slave = StartSlave(detector.get());
  ASSERT_SOME(slave);

  AWAIT_READY(slaveRegisteredMessage);

  // Return a pending future from the rate limiter.
  Future<Nothing> acquire;
  Promise<Nothing> promise;
  EXPECT_CALL(*slaveRemovalLimiter, acquire())
    .WillOnce(DoAll(FutureSatisfy(&acquire),
                    Return(promise.future())));

  // Induce a health check failure of the slave.
  Clock::pause();
  size_t pings = 0;
  while (true) {
    AWAIT_READY(ping);
    pings++;
    if (pings == masterFlags.max_slave_ping_timeouts) {
      Clock::advance(masterFlags.slave_ping_timeout);
      break;
    }
    ping = FUTURE_MESSAGE(Eq(PingSlaveMessage().GetTypeName()), _, _);
    Clock::advance(masterFlags.slave_ping_timeout);
  }

  // The master should attempt to acquire a permit.
  AWAIT_READY(acquire);

  // Settle to make sure the shutdown does not occur.
  Clock::settle();

  // Reset the filters to allow pongs from the slave.
  filter(NULL);

  // Advance clock enough to do a ping pong.
  Clock::advance(masterFlags.slave_ping_timeout);
  Clock::settle();

  // The master should have tried to cancel the removal.
  ASSERT_TRUE(promise.future().hasDiscard());

  // Allow the cancelation and settle the clock to ensure a shutdown
  // does not occur.
  promise.discard();
  Clock::settle();
}