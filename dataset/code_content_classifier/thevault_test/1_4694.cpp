void ManipulateModuleManagerAndSelectedFunctionsToAddInstrumentedFunctionFromOffset(
    orbit_client_data::ModuleManager* module_manager,
    absl::flat_hash_map<uint64_t, orbit_client_protos::FunctionInfo>* selected_functions,
    const std::string& file_path, uint64_t file_offset, uint64_t function_size,
    uint64_t function_id) {
  ErrorMessageOr<std::unique_ptr<orbit_object_utils::ElfFile>> error_or_elf_file =
      orbit_object_utils::CreateElfFile(std::filesystem::path{file_path});
  FAIL_IF(error_or_elf_file.has_error(), "%s", error_or_elf_file.error().message());
  std::unique_ptr<orbit_object_utils::ElfFile>& elf_file = error_or_elf_file.value();
  std::string build_id = elf_file->GetBuildId();
  uint64_t load_bias = elf_file->GetLoadBias();

  orbit_grpc_protos::ModuleInfo module_info;
  module_info.set_file_path(file_path);
  module_info.set_build_id(build_id);
  module_info.set_load_bias(load_bias);
  module_info.set_executable_segment_offset(elf_file->GetExecutableSegmentOffset());
  CHECK(module_manager->AddOrUpdateModules({module_info}).empty());

  orbit_client_protos::FunctionInfo function_info;
  function_info.set_module_path(file_path);
  function_info.set_module_build_id(build_id);
  function_info.set_address(load_bias + file_offset);
  function_info.set_size(function_size);
  selected_functions->emplace(function_id, function_info);
}