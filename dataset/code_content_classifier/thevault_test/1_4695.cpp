std::optional<orbit_grpc_protos::ModuleSymbols> FindAndLoadDebugSymbols(
    const std::string& file_path) {
  std::vector<std::filesystem::path> candidate_paths = {file_path};
  std::filesystem::path file_name = std::filesystem::path{file_path}.filename();
  std::filesystem::path file_dir = std::filesystem::path{file_path}.parent_path();
  static constexpr const char* kDebugFileExt = ".debug";
  {
    std::filesystem::path file_name_dot_debug{file_name};
    file_name_dot_debug.replace_extension(kDebugFileExt);
    candidate_paths.emplace_back(file_dir / file_name_dot_debug);
  }
  {
    std::filesystem::path file_name_plus_debug{file_name.string() + kDebugFileExt};
    candidate_paths.emplace_back(file_dir / file_name_plus_debug);
  }

  for (const std::filesystem::path& candidate_path : candidate_paths) {
    ErrorMessageOr<bool> error_or_exists = orbit_base::FileExists(candidate_path);
    FAIL_IF(error_or_exists.has_error(), "%s", error_or_exists.error().message());
    if (!error_or_exists.value()) {
      continue;
    }

    ErrorMessageOr<std::unique_ptr<orbit_object_utils::ElfFile>> error_or_elf_file =
        orbit_object_utils::CreateElfFile(candidate_path);
    if (error_or_elf_file.has_error()) {
      ERROR("%s", error_or_elf_file.error().message());
      continue;
    }
    std::unique_ptr<orbit_object_utils::ElfFile>& elf_file = error_or_elf_file.value();

    ErrorMessageOr<orbit_grpc_protos::ModuleSymbols> symbols_or_error =
        elf_file->LoadDebugSymbols();
    // Load debug symbols from the first of the candidate files that contains any.
    if (symbols_or_error.has_error()) {
      continue;
    }

    LOG("Loaded debug symbols of module \"%s\" from \"%s\"", file_name.string(),
        elf_file->GetName());
    return symbols_or_error.value();
  }

  ERROR("Could not find debug symbols of module \"%s\"", file_name.string());
  return std::nullopt;
}