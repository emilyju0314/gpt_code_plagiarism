TEST_F(PersistentVolumeEndpointsTest, VolumeExceedsReservedSize)
{
  TestAllocator<> allocator;

  EXPECT_CALL(allocator, initialize(_, _, _, _));

  Try<Owned<cluster::Master>> master = StartMaster(&allocator);
  ASSERT_SOME(master);

  Future<SlaveID> slaveId;
  EXPECT_CALL(allocator, addSlave(_, _, _, _, _))
    .WillOnce(DoAll(InvokeAddSlave(&allocator),
                    FutureArg<0>(&slaveId)));

  slave::Flags slaveFlags = CreateSlaveFlags();
  slaveFlags.resources = "disk(role1):1024";

  Owned<MasterDetector> detector = master.get()->createDetector();
  Try<Owned<cluster::Slave>> slave = StartSlave(detector.get(), slaveFlags);
  ASSERT_SOME(slave);

  Resources volume = createPersistentVolume(
      Megabytes(1025),
      "role1",
      "id1",
      "path1");

  Future<Response> createResponse = process::http::post(
      master.get()->pid,
      "create-volumes",
      createBasicAuthHeaders(DEFAULT_CREDENTIAL),
      createRequestBody(slaveId.get(), "volumes", volume));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(Conflict().status, createResponse);
}