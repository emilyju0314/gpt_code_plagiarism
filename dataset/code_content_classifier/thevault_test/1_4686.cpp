static void SendUprobesFullAddressInfoToListener(
    TracerListener* listener, const unwindstack::FrameData& libunwindstack_frame) {
  CHECK(listener != nullptr);

  FullAddressInfo address_info;
  address_info.set_absolute_address(libunwindstack_frame.pc);
  address_info.set_function_name("[uprobes]");
  address_info.set_offset_in_function(libunwindstack_frame.pc - libunwindstack_frame.map_start);
  address_info.set_module_name("[uprobes]");

  listener->OnAddressInfo(std::move(address_info));
}