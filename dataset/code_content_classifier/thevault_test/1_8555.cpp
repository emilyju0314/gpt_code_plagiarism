TEST_F(PersistentVolumeEndpointsTest, GoodCreateACLMultipleRoles)
{
  const string AUTHORIZED_ROLE_1 = "potato_head";
  const string AUTHORIZED_ROLE_2 = "gumby";

  TestAllocator<> allocator;
  ACLs acls;

  // This ACL asserts that the principal of `DEFAULT_CREDENTIAL`
  // can create volumes for any role.
  mesos::ACL::CreateVolume* create = acls.add_create_volumes();
  create->mutable_principals()->add_values(DEFAULT_CREDENTIAL.principal());
  create->mutable_roles()->set_type(mesos::ACL::Entity::ANY);

  // Create a master.
  master::Flags masterFlags = CreateMasterFlags();
  masterFlags.acls = acls;

  EXPECT_CALL(allocator, initialize(_, _, _, _));

  Try<Owned<cluster::Master>> master = StartMaster(&allocator, masterFlags);
  ASSERT_SOME(master);

  // Create a slave. Disk resources are statically reserved to allow the
  // creation of a persistent volume.
  slave::Flags slaveFlags = CreateSlaveFlags();
  slaveFlags.resources =
    "cpus:1;mem:512;disk(" + AUTHORIZED_ROLE_1 +"):1024;disk(" +
    AUTHORIZED_ROLE_2 + "):1024";

  Future<SlaveID> slaveId;
  EXPECT_CALL(allocator, addSlave(_, _, _, _, _))
    .WillOnce(DoAll(InvokeAddSlave(&allocator), FutureArg<0>(&slaveId)));

  Owned<MasterDetector> detector = master.get()->createDetector();
  Try<Owned<cluster::Slave>> slave = StartSlave(detector.get(), slaveFlags);
  ASSERT_SOME(slave);

  Resources volume1 = createPersistentVolume(
      Megabytes(64),
      AUTHORIZED_ROLE_1,
      "id1",
      "path1");

  Resources volume2 = createPersistentVolume(
      Megabytes(64),
      AUTHORIZED_ROLE_2,
      "id2",
      "path2");

  Resources volumesMultipleRoles = volume1 + volume2;

  Future<Response> response = process::http::post(
      master.get()->pid,
      "create-volumes",
      createBasicAuthHeaders(DEFAULT_CREDENTIAL),
      createRequestBody(slaveId.get(), "volumes", volumesMultipleRoles));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(OK().status, response);
}