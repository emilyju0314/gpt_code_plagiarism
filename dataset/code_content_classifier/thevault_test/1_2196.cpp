TEST_F(CompositeMetadataTestCase, GetMetadataAfterCompositeReassemble) {
  char buf[32] = "";
  size_t len = 0;
  size_t device_indexes[3];
  uint32_t protocol_id[] = {
      ZX_PROTOCOL_GPIO,
      ZX_PROTOCOL_I2C,
      ZX_PROTOCOL_ETHERNET,
  };

  static_assert(fbl::count_of(protocol_id) == fbl::count_of(device_indexes));

  const device_metadata_t metadata[] = {
      {
          .type = kMetadataKey,
          .data = const_cast<char*>(kMetadataStr),
          .length = strlen(kMetadataStr) + 1,
      },
  };

  const char* kCompositeDevName = "composite-dev";
  ASSERT_NO_FATAL_FAILURES(BindCompositeDefineComposite(
      platform_bus(), protocol_id, fbl::count_of(protocol_id), nullptr /* props */, 0,
      kCompositeDevName, ZX_OK, metadata, countof(metadata)));

  // Add the devices to construct the composite out of.
  for (size_t i = 0; i < fbl::count_of(device_indexes); ++i) {
    char name[32];
    snprintf(name, sizeof(name), "device-%zu", i);
    ASSERT_NO_FATAL_FAILURES(
        AddDevice(platform_bus(), name, protocol_id[i], "", &device_indexes[i]));
  }

  size_t component_device_indexes[fbl::count_of(device_indexes)];
  ASSERT_NO_FATAL_FAILURES(CheckCompositeCreation(
      kCompositeDevName, device_indexes, fbl::count_of(device_indexes), component_device_indexes,
      &composite_remote_coordinator, &composite_remote_controller));
  composite_device = GetCompositeDeviceFromComponent(kCompositeDevName, device_indexes[0]);
  ASSERT_NOT_NULL(composite_device);

  // Get and verify metadata
  ASSERT_OK(
      platform_bus()->coordinator->GetMetadata(composite_device, kMetadataKey, buf, 32, &len));
  VerifyMetadata(buf, len);

  // Remove device 0 and its children (component and composite devices).
  ASSERT_NO_FATAL_FAILURES(coordinator_.ScheduleRemove(device(device_indexes[0])->device));
  coordinator_loop()->RunUntilIdle();

  zx::channel& device_remote = device(device_indexes[0])->controller_remote;
  zx::channel& component_remote = device(component_device_indexes[0])->controller_remote;

  // The device and composite should not have received an unbind request yet.
  ASSERT_FALSE(DeviceHasPendingMessages(device_remote));
  ASSERT_FALSE(DeviceHasPendingMessages(composite_remote_controller));

  // Check the component and composite are unbound.
  ASSERT_NO_FATAL_FAILURES(CheckUnbindReceivedAndReply(component_remote));
  coordinator_loop()->RunUntilIdle();

  ASSERT_FALSE(DeviceHasPendingMessages(device_remote));
  ASSERT_FALSE(DeviceHasPendingMessages(component_remote));

  ASSERT_NO_FATAL_FAILURES(CheckUnbindReceivedAndReply(composite_remote_controller));
  coordinator_loop()->RunUntilIdle();

  // Still waiting for the composite to be removed.
  ASSERT_FALSE(DeviceHasPendingMessages(device_remote));
  ASSERT_FALSE(DeviceHasPendingMessages(component_remote));

  // Finish removing the composite.
  ASSERT_NO_FATAL_FAILURES(CheckRemoveReceivedAndReply(composite_remote_controller));
  coordinator_loop()->RunUntilIdle();

  ASSERT_FALSE(DeviceHasPendingMessages(device_remote));

  // Finish removing the component.
  ASSERT_NO_FATAL_FAILURES(CheckRemoveReceivedAndReply(component_remote));
  coordinator_loop()->RunUntilIdle();

  ASSERT_NO_FATAL_FAILURES(CheckRemoveReceivedAndReply(device_remote));
  coordinator_loop()->RunUntilIdle();

  // Add the device back and verify the composite gets created again
  ASSERT_NO_FATAL_FAILURES(
      AddDevice(platform_bus(), "device-0", protocol_id[0], "", &device_indexes[0]));
  {
    auto device_state = device(device_indexes[0]);
    // Wait for the components to get bound
    fbl::String driver = coordinator()->component_driver()->libname;
    ASSERT_NO_FATAL_FAILURES(
        CheckBindDriverReceived(device_state->controller_remote, driver.data()));
    coordinator_loop()->RunUntilIdle();

    // Synthesize the AddDevice request the component driver would send
    ASSERT_NO_FATAL_FAILURES(AddDevice(device_state->device, "component-device-0", 0, driver,
                                       &component_device_indexes[0]));
  }
  ASSERT_NO_FATAL_FAILURES(CheckCreateCompositeDeviceReceived(
      devhost_remote(), kCompositeDevName, fbl::count_of(device_indexes),
      &composite_remote_coordinator, &composite_remote_controller));

  composite_device = GetCompositeDeviceFromComponent(kCompositeDevName, device_indexes[0]);
  ASSERT_NOT_NULL(composite_device);

  // Get and verify metadata again
  ASSERT_OK(
      platform_bus()->coordinator->GetMetadata(composite_device, kMetadataKey, buf, 32, &len));
  VerifyMetadata(buf, len);
}