std::vector<config::Environment> LookupCobaltEnvironment(const std::string& environment_dir) {
  auto environment_path = files::JoinPath(environment_dir, kCobaltEnvironmentFile);
  std::string cobalt_environment;
  if (files::ReadFileToString(environment_path, &cobalt_environment)) {
    FX_LOGS(INFO) << "Loaded Cobalt environment from config file " << environment_path << ": "
                  << cobalt_environment;
    if (cobalt_environment == "LOCAL")
      return std::vector({config::Environment::LOCAL});
    if (cobalt_environment == "PROD")
      return std::vector({config::Environment::PROD});
    if (cobalt_environment == "DEVEL")
      return std::vector({config::Environment::DEVEL});
    // TODO(camrdale): remove this once the log source transition is complete.
    if (cobalt_environment == "DEVEL_AND_PROD")
      return std::vector({config::Environment::DEVEL, config::Environment::PROD});
    FX_LOGS(ERROR) << "Failed to parse the contents of config file " << environment_path << ": "
                   << cobalt_environment
                   << ". Falling back to default environment: " << kDefaultEnvironment;
  } else {
    FX_LOGS(ERROR) << "Failed to read config file " << environment_path
                   << ". Falling back to default environment: " << kDefaultEnvironment;
  }
  return std::vector({kDefaultEnvironment});
}