TEST_F(PersistentVolumeEndpointsTest, SlavesEndpointFullResources)
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
  slaveFlags.resources = "cpus:4;mem:2048;disk:4096";

  Owned<MasterDetector> detector = master.get()->createDetector();
  Try<Owned<cluster::Slave>> slave = StartSlave(detector.get(), slaveFlags);
  ASSERT_SOME(slave);

  FrameworkInfo frameworkInfo = createFrameworkInfo();

  Resources unreserved = Resources::parse("cpus:1;mem:512;disk:1024").get();
  Resources dynamicallyReserved = unreserved.flatten(
      frameworkInfo.role(),
      createReservationInfo(DEFAULT_CREDENTIAL.principal()));

  Future<Response> response = process::http::post(
      master.get()->pid,
      "reserve",
      createBasicAuthHeaders(DEFAULT_CREDENTIAL),
      createRequestBody(slaveId.get(), "resources", dynamicallyReserved));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(OK().status, response);

  Resources volume = createPersistentVolume(
      Megabytes(64),
      frameworkInfo.role(),
      "id1",
      "path1",
      DEFAULT_CREDENTIAL.principal());

  response = process::http::post(
      master.get()->pid,
      "create-volumes",
      createBasicAuthHeaders(DEFAULT_CREDENTIAL),
      createRequestBody(slaveId.get(), "volumes", volume));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(OK().status, response);

  // Start a framework and launch a task on some (but not all) of the
  // reserved resources at the slave.
  MockScheduler sched;
  MesosSchedulerDriver driver(
      &sched, frameworkInfo, master.get()->pid, DEFAULT_CREDENTIAL);

  Future<vector<Offer>> offers;

  EXPECT_CALL(sched, registered(&driver, _, _));

  EXPECT_CALL(sched, resourceOffers(&driver, _))
    .WillOnce(FutureArg<1>(&offers));

  driver.start();

  AWAIT_READY(offers);

  ASSERT_EQ(1u, offers.get().size());
  Offer offer = offers.get()[0];

  EXPECT_TRUE(Resources(offer.resources()).contains(volume));

  Resources taskUnreserved = Resources::parse("cpus:1;mem:256").get();
  Resources taskResources = taskUnreserved.flatten(
      frameworkInfo.role(),
      createReservationInfo(DEFAULT_CREDENTIAL.principal()));

  TaskInfo taskInfo = createTask(offer.slave_id(), taskResources, "sleep 1000");

  // We use the filter explicitly here so that the resources will not
  // be filtered for 5 seconds (the default).
  Filters filters;
  filters.set_refuse_seconds(0);

  // Expect a TASK_RUNNING status.
  EXPECT_CALL(sched, statusUpdate(&driver, _));

  Future<Nothing> _statusUpdateAcknowledgement =
    FUTURE_DISPATCH(_, &Slave::_statusUpdateAcknowledgement);

  // Expect another resource offer.
  EXPECT_CALL(sched, resourceOffers(&driver, _))
    .WillOnce(FutureArg<1>(&offers));

  driver.acceptOffers({offer.id()}, {LAUNCH({taskInfo})}, filters);

  // Wait for TASK_RUNNING update ack.
  AWAIT_READY(_statusUpdateAcknowledgement);

  response = process::http::get(
      master.get()->pid,
      "slaves",
      None(),
      createBasicAuthHeaders(DEFAULT_CREDENTIAL));

  AWAIT_EXPECT_RESPONSE_STATUS_EQ(OK().status, response);
  AWAIT_EXPECT_RESPONSE_HEADER_EQ(APPLICATION_JSON, "Content-Type", response);

  Try<JSON::Object> parse = JSON::parse<JSON::Object>(response.get().body);

  ASSERT_SOME(parse);

  JSON::Object slavesObject = parse.get();

  ASSERT_TRUE(slavesObject.values["slaves"].is<JSON::Array>());
  JSON::Array slaveArray = slavesObject.values["slaves"].as<JSON::Array>();

  EXPECT_EQ(1u, slaveArray.values.size());

  ASSERT_TRUE(slaveArray.values[0].is<JSON::Object>());
  JSON::Object slaveObject = slaveArray.values[0].as<JSON::Object>();

  Try<JSON::Value> expectedReserved = JSON::parse(
      R"~(
      {
        "role1": [
          {
            "name": "cpus",
            "type": "SCALAR",
            "scalar": {
              "value": 1.0
            },
            "role": "role1",
            "reservation": {
              "principal": "test-principal"
            }
          },
          {
            "name": "mem",
            "type": "SCALAR",
            "scalar": {
              "value": 512.0
            },
            "role": "role1",
            "reservation": {
              "principal": "test-principal"
            }
          },
          {
            "name": "disk",
            "type": "SCALAR",
            "scalar": {
              "value": 960.0
            },
            "role": "role1",
            "reservation": {
              "principal": "test-principal"
            }
          },
          {
            "name": "disk",
            "type": "SCALAR",
            "scalar": {
              "value": 64.0
            },
            "role": "role1",
            "reservation": {
              "principal": "test-principal"
            },
            "disk": {
              "persistence": {
                "id": "id1"
              },
              "volume": {
                "mode": "RW",
                "container_path": "path1"
              }
            }
          }
        ]
      })~");

  ASSERT_SOME(expectedReserved);

  Try<JSON::Value> expectedUsed = JSON::parse(
      R"~(
      [
        {
          "name": "cpus",
          "reservation": {
            "principal": "test-principal"
          },
          "role": "role1",
          "scalar": {
            "value": 1.0
          },
          "type": "SCALAR"
        },
        {
          "name": "mem",
          "reservation": {
            "principal": "test-principal"
          },
          "role": "role1",
          "scalar": {
            "value": 256.0
          },
          "type": "SCALAR"
        }
      ])~");

  ASSERT_SOME(expectedUsed);

  Try<JSON::Value> expectedOffered = JSON::parse(
      R"~(
      [
        {
          "disk": {
            "persistence": {
              "id": "id1"
            },
            "volume": {
              "container_path": "path1",
              "mode": "RW"
            }
          },
          "name": "disk",
          "reservation": {
            "principal": "test-principal"
          },
          "role": "role1",
          "scalar": {
            "value": 64.0
          },
          "type": "SCALAR"
        },
        {
          "name": "mem",
          "reservation": {
            "principal": "test-principal"
          },
          "role": "role1",
          "scalar": {
            "value": 256.0
          },
          "type": "SCALAR"
        },
        {
          "name": "disk",
          "reservation": {
            "principal": "test-principal"
          },
          "role": "role1",
          "scalar": {
            "value": 960.0
          },
          "type": "SCALAR"
        },
        {
          "name": "cpus",
          "role": "*",
          "scalar": {
            "value": 3.0
          },
          "type": "SCALAR"
        },
        {
          "name": "mem",
          "role": "*",
          "scalar": {
            "value": 1536.0
          },
          "type": "SCALAR"
        },
        {
          "name": "disk",
          "role": "*",
          "scalar": {
            "value": 3072.0
          },
          "type": "SCALAR"
        },
        {
          "name": "ports",
          "ranges": {
            "range": [
              {
                "begin": 31000,
                "end": 32000
              }
            ]
          },
          "role": "*",
          "type": "RANGES"
        }
      ])~");

  ASSERT_SOME(expectedOffered);

  JSON::Value reservedValue = slaveObject.values["reserved_resources_full"];
  EXPECT_EQ(expectedReserved.get(), reservedValue);

  JSON::Value usedValue = slaveObject.values["used_resources_full"];
  EXPECT_EQ(expectedUsed.get(), usedValue);

  JSON::Value offeredValue = slaveObject.values["offered_resources_full"];
  EXPECT_EQ(expectedOffered.get(), offeredValue);

  driver.stop();
  driver.join();
}