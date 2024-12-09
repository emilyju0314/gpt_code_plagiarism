void Touch(const fs::path& path) {
  if (ErrorMessageOr<void> result = orbit_base::WriteStringToFile(path, "\n"); result.has_error()) {
    ERROR("%s", result.error().message());
  }
}