ErrorMessageOr<std::filesystem::path> GetLibraryPath() {
  // When packaged, liborbituserspaceinstrumentation.so is found alongside OrbitService. In
  // development, it is found in "../lib", relative to OrbitService.
  constexpr const char* kLibName = "liborbituserspaceinstrumentation.so";
  const std::filesystem::path exe_dir = orbit_base::GetExecutableDir();
  std::vector<std::filesystem::path> potential_paths = {exe_dir / kLibName,
                                                        exe_dir / ".." / "lib" / kLibName};
  /* copybara:insert(In internal tests the library is in a different place)
  potential_paths.emplace_back(initial_current_path /
  "@@LIB_ORBIT_USER_SPACE_INSTRUMENTATION_PATH@@");
  */
  for (const auto& path : potential_paths) {
    if (std::filesystem::exists(path)) {
      return path;
    }
  }
  return ErrorMessage(absl::StrFormat("%s not found on system.", kLibName));
}