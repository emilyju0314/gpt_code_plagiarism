TEST_F(PersistentVolumeEndpointsTest, NoAuthentication)
{
  const string TEST_ROLE = "role1";

  TestAllocator<> allocator;

  // Create master flags that will disable authentication.
  master::Flags masterFlags = CreateMasterFlags();
  masterFlags.authenticate_http = false;

  EXPECT_CALL(allocator, initialize(_, _, _, _));

  Try<Owned<cluster::Master>> master = StartMaster(&allocator, masterFlags);
  ASSERT_SOME(master);

  // Create an agent with statically reserved disk resources to allow the
  // creation of a persistent volume.
  slave::Flags slaveFlags = CreateSlaveFlags();
  slaveFlags.resources = "cpus:1;mem:512;disk(" + TEST_ROLE + "):1024";

  Future<SlaveID> slaveId;
  EXPECT_CALL(allocator, addSlave(_, _, _, _, _))
    .WillOnce(DoAll(InvokeAddSlave(&allocator), FutureArg<0>(&slaveId)));

  Owned<MasterDetector> detector = master.get()->createDetector();
  Try<Owned<cluster::Slave>> slave = StartSlave(detector.get(), slaveFlags);
  ASSERT_SOME(slave);

  AWAIT_READY(slaveId);

  Resources volume = createPersistentVolume(
      Megabytes(64),
      TEST_ROLE,
      "id1",
      "path1");

  // Make a request to create a volume with no authentication header.
  {
    Future<Response> response = process::http::post(
        master.get()->pid,
        "create-volumes",
        None(),
        createRequestBody(slaveId.get(), "volumes", volume));

    AWAIT_EXPECT_RESPONSE_STATUS_EQ(OK().status, response);
  }

  // Make a request to destroy a volume with no authentication header.
  {
    Future<Response> response = process::http::post(
        master.get()->pid,
        "destroy-volumes",
        None(),
        createRequestBody(slaveId.get(), "volumes", volume));

    AWAIT_EXPECT_RESPONSE_STATUS_EQ(OK().status, response);
  }
}