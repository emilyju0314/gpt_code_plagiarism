TEST_F(PersistentVolumeEndpointsTest, DeleteNonExistentVolume)
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
      Megabytes(64),
      "role1",
      "id1",
      "path1");

  Future<Response> createResponse = process::http::post(
      master.get()->pid,
      "create-volumes",
      createBasicAuthHeaders(DEFAULT_CREDENTIAL),
      createRequestBody(slaveId.get(), "volumes", volume));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(OK().status, createResponse);

  // Non-existent volume ID.
  Resources badVolumeId = createPersistentVolume(
      Megabytes(64),
      "role1",
      "id2",
      "path1");

  Future<Response> destroyResponse = process::http::post(
      master.get()->pid,
      "destroy-volumes",
      createBasicAuthHeaders(DEFAULT_CREDENTIAL),
      createRequestBody(slaveId.get(), "volumes", badVolumeId));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(BadRequest().status, destroyResponse);

  // Non-existent role.
  Resources badRole = createPersistentVolume(
      Megabytes(64),
      "role2",
      "id1",
      "path1");

  destroyResponse = process::http::post(
      master.get()->pid,
      "destroy-volumes",
      createBasicAuthHeaders(DEFAULT_CREDENTIAL),
      createRequestBody(slaveId.get(), "volumes", badRole));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(BadRequest().status, destroyResponse);

  // Size mismatch.
  Resources badSize = createPersistentVolume(
      Megabytes(128),
      "role1",
      "id1",
      "path1");

  destroyResponse = process::http::post(
      master.get()->pid,
      "destroy-volumes",
      createBasicAuthHeaders(DEFAULT_CREDENTIAL),
      createRequestBody(slaveId.get(), "volumes", badSize));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(BadRequest().status, destroyResponse);

  // NOTE: Two persistent volumes with different paths are considered
  // equivalent, so the destroy operation will succeed. It is unclear
  // whether this behavior is desirable (MESOS-3961).
  Resources differentPath = createPersistentVolume(
      Megabytes(64),
      "role1",
      "id1",
      "path2");

  destroyResponse = process::http::post(
      master.get()->pid,
      "destroy-volumes",
      createBasicAuthHeaders(DEFAULT_CREDENTIAL),
      createRequestBody(slaveId.get(), "volumes", differentPath));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(OK().status, destroyResponse);
}