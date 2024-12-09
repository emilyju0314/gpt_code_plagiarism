TEST_F(CompositeTestCase, Topology) {
  size_t device_indexes[2];
  uint32_t protocol_id[] = {
      ZX_PROTOCOL_GPIO,
      ZX_PROTOCOL_I2C,
  };
  static_assert(fbl::count_of(protocol_id) == fbl::count_of(device_indexes));

  const char* kCompositeDevName = "composite-dev";
  ASSERT_NO_FATAL_FAILURES(BindCompositeDefineComposite(platform_bus(), protocol_id,
                                                        fbl::count_of(protocol_id),
                                                        nullptr /* props */, 0, kCompositeDevName));
  // Add the devices to construct the composite out of.
  for (size_t i = 0; i < fbl::count_of(device_indexes); ++i) {
    char name[32];
    snprintf(name, sizeof(name), "device-%zu", i);
    ASSERT_NO_FATAL_FAILURES(
        AddDevice(platform_bus(), name, protocol_id[i], "", &device_indexes[i]));
  }

  zx::channel composite_remote_coordinator;
  zx::channel composite_remote_controller;
  size_t component_device_indexes[fbl::count_of(device_indexes)];
  ASSERT_NO_FATAL_FAILURES(CheckCompositeCreation(
      kCompositeDevName, device_indexes, fbl::count_of(device_indexes), component_device_indexes,
      &composite_remote_coordinator, &composite_remote_controller));

  devmgr::Devnode* dn = coordinator()->root_device()->self;
  fbl::RefPtr<devmgr::Device> composite_dev;
  ASSERT_OK(devmgr::devfs_walk(dn, "composite-dev", &composite_dev));

  char path_buf[PATH_MAX];
  ASSERT_OK(coordinator()->GetTopologicalPath(composite_dev, path_buf, sizeof(path_buf)));
  ASSERT_STR_EQ(path_buf, "/dev/composite-dev");
}