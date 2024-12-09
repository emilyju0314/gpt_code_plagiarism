TEST_F(PersistentVolumeEndpointsTest, BadCreateAndDestroyACL)
{
  // Pause the clock to gain control over the offer cycle.
  Clock::pause();

  TestAllocator<> allocator;
  ACLs acls;

  // This ACL asserts that the principal of `DEFAULT_CREDENTIAL`
  // cannot create persistent volumes.
  mesos::ACL::CreateVolume* cannotCreate = acls.add_create_volumes();
  cannotCreate->mutable_principals()->add_values(
      DEFAULT_CREDENTIAL.principal());
  cannotCreate->mutable_roles()->set_type(mesos::ACL::Entity::NONE);

  // This ACL asserts that the principal of `DEFAULT_CREDENTIAL_2`
  // can create persistent volumes for any role.
  mesos::ACL::CreateVolume* canCreate = acls.add_create_volumes();
  canCreate->mutable_principals()->add_values(DEFAULT_CREDENTIAL_2.principal());
  canCreate->mutable_roles()->set_type(mesos::ACL::Entity::ANY);

  // This ACL asserts that the principal of `DEFAULT_CREDENTIAL`
  // cannot destroy persistent volumes.
  mesos::ACL::DestroyVolume* cannotDestroy = acls.add_destroy_volumes();
  cannotDestroy->mutable_principals()->add_values(
      DEFAULT_CREDENTIAL.principal());
  cannotDestroy->mutable_creator_principals()->set_type(
      mesos::ACL::Entity::NONE);

  // Create a master.
  master::Flags masterFlags = CreateMasterFlags();
  masterFlags.acls = acls;

  EXPECT_CALL(allocator, initialize(_, _, _, _));

  Try<Owned<cluster::Master>> master = StartMaster(&allocator, masterFlags);
  ASSERT_SOME(master);

  // Create a slave. Disk resources are statically reserved to allow the
  // creation of a persistent volume.
  slave::Flags slaveFlags = CreateSlaveFlags();
  slaveFlags.resources = "cpus:1;mem:512;disk(role1):1024";

  Future<SlaveID> slaveId;
  EXPECT_CALL(allocator, addSlave(_, _, _, _, _))
    .WillOnce(DoAll(InvokeAddSlave(&allocator),
                    FutureArg<0>(&slaveId)));

  Owned<MasterDetector> detector = master.get()->createDetector();
  Try<Owned<cluster::Slave>> slave = StartSlave(detector.get(), slaveFlags);
  ASSERT_SOME(slave);

  Resources volume = createPersistentVolume(
      Megabytes(64),
      "role1",
      "id1",
      "path1");

  // The failed creation attempt.
  Future<Response> createResponse = process::http::post(
      master.get()->pid,
      "create-volumes",
      createBasicAuthHeaders(DEFAULT_CREDENTIAL),
      createRequestBody(slaveId.get(), "volumes", volume));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(Forbidden().status, createResponse);

  // The successful creation attempt.
  createResponse = process::http::post(
      master.get()->pid,
      "create-volumes",
      createBasicAuthHeaders(DEFAULT_CREDENTIAL_2),
      createRequestBody(slaveId.get(), "volumes", volume));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(OK().status, createResponse);

  FrameworkInfo frameworkInfo = createFrameworkInfo();

  MockScheduler sched;
  MesosSchedulerDriver driver(
      &sched, frameworkInfo, master.get()->pid, DEFAULT_CREDENTIAL);

  Future<vector<Offer>> offers;

  EXPECT_CALL(sched, registered(&driver, _, _));

  EXPECT_CALL(sched, resourceOffers(&driver, _))
    .WillOnce(FutureArg<1>(&offers));

  driver.start();

  Clock::settle();
  Clock::advance(DEFAULT_ALLOCATION_INTERVAL);

  AWAIT_READY(offers);

  ASSERT_EQ(1u, offers.get().size());
  Offer offer = offers.get()[0];

  EXPECT_TRUE(Resources(offer.resources()).contains(volume));

  // The failed destruction attempt.
  Future<Response> destroyResponse = process::http::post(
      master.get()->pid,
      "destroy-volumes",
      createBasicAuthHeaders(DEFAULT_CREDENTIAL),
      createRequestBody(slaveId.get(), "volumes", volume));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(Forbidden().status, destroyResponse);

  driver.stop();
  driver.join();
}