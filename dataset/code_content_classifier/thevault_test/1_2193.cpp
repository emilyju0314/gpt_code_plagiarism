void BindCompositeDefineComposite(const fbl::RefPtr<devmgr::Device>& platform_bus,
                                  const uint32_t* protocol_ids, size_t component_count,
                                  const zx_device_prop_t* props, size_t props_count,
                                  const char* name, zx_status_t expected_status = ZX_OK,
                                  const device_metadata_t* metadata = nullptr,
                                  size_t metadata_count = 0) {
  std::vector<llcpp::fuchsia::device::manager::DeviceComponent> components = {};
  for (size_t i = 0; i < component_count; ++i) {
    // Define a union type to avoid violating the strict aliasing rule.

    zx_bind_inst_t always = BI_MATCH();
    zx_bind_inst_t protocol = BI_MATCH_IF(EQ, BIND_PROTOCOL, protocol_ids[i]);

    llcpp::fuchsia::device::manager::DeviceComponent component;  // = &components[i];
    component.parts_count = 2;
    component.parts[0].match_program_count = 1;
    component.parts[0].match_program[0] = ::llcpp::fuchsia::device::manager::BindInstruction{
        .op = always.op,
        .arg = always.arg,
    };
    component.parts[1].match_program_count = 1;
    component.parts[1].match_program[0] = ::llcpp::fuchsia::device::manager::BindInstruction{
        .op = protocol.op,
        .arg = protocol.arg,
    };
    components.push_back(component);
  }

  auto prop_view = ::fidl::VectorView<uint64_t>(
      reinterpret_cast<uint64_t*>(const_cast<zx_device_prop_t*>(props)), props_count);

  std::vector<llcpp::fuchsia::device::manager::DeviceMetadata> metadata_list = {};
  for (size_t i = 0; i < metadata_count; i++) {
    auto meta = llcpp::fuchsia::device::manager::DeviceMetadata{
        .key = metadata[i].type,
        .data = ::fidl::VectorView(reinterpret_cast<uint8_t*>(const_cast<void*>(metadata[i].data)),
                                   metadata[i].length)};
    metadata_list.push_back(meta);
  }

  llcpp::fuchsia::device::manager::CompositeDeviceDescriptor comp_desc = {
      .props = prop_view,
      .components = ::fidl::VectorView(components),
      .coresident_device_index = 0,
      .metadata = ::fidl::VectorView(metadata_list),
  };

  devmgr::Coordinator* coordinator = platform_bus->coordinator;
  ASSERT_EQ(coordinator->AddCompositeDevice(platform_bus, name, comp_desc), expected_status);
}