TEST_F(PersistentVolumeEndpointsTest, GoodCreateAndDestroyACLBadCredential)
{
  // Pause the clock to gain control over the offer cycle.
  Clock::pause();

  // Create a credential which will not be listed
  // for valid authentication with the master.
  Credential failedCredential;
  failedCredential.set_principal("awesome-principal");
  failedCredential.set_secret("super-secret-secret");

  TestAllocator<> allocator;
  ACLs acls;

  // This ACL asserts that the principal of `failedCredential`
  // can create persistent volumes for any role.
  mesos::ACL::CreateVolume* failedCreate = acls.add_create_volumes();
  failedCreate->mutable_principals()->add_values(failedCredential.principal());
  failedCreate->mutable_roles()->set_type(mesos::ACL::Entity::ANY);

  // This ACL asserts that the principal of `failedCredential`
  // can destroy persistent volumes.
  mesos::ACL::DestroyVolume* failedDestroy = acls.add_destroy_volumes();
  failedDestroy->mutable_principals()->add_values(failedCredential.principal());
  failedDestroy->mutable_creator_principals()->set_type(
      mesos::ACL::Entity::ANY);

  // This ACL asserts that the principal of `DEFAULT_CREDENTIAL`
  // can create persistent volumes for any role.
  mesos::ACL::CreateVolume* canCreate = acls.add_create_volumes();
  canCreate->mutable_principals()->add_values(DEFAULT_CREDENTIAL.principal());
  canCreate->mutable_roles()->set_type(mesos::ACL::Entity::ANY);

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
      createBasicAuthHeaders(failedCredential),
      createRequestBody(slaveId.get(), "volumes", volume));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(
      Unauthorized({}).status,
      createResponse);

  // The successful creation attempt.
  createResponse = process::http::post(
      master.get()->pid,
      "create-volumes",
      createBasicAuthHeaders(DEFAULT_CREDENTIAL),
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
      createBasicAuthHeaders(failedCredential),
      createRequestBody(slaveId.get(), "volumes", volume));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(
      Unauthorized({}).status,
      destroyResponse);

  driver.stop();
  driver.join();
}