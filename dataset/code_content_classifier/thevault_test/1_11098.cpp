void ParseArguments(int *argc, char ***argv) {
  std::string usage;
  if (*argc) {
    usage += (*argv)[0];
    usage += " -v | --version | ";
    usage += (*argv)[0];
  }
  usage += " [.tr files ...]";
  tesseract::ParseCommandLineFlags(usage.c_str(), argc, argv, true);
  // Set some global values based on the flags.
  Config.MinSamples =
      std::max(0.0, std::min(1.0, double(FLAGS_clusterconfig_min_samples_fraction)));
  Config.MaxIllegal = std::max(0.0, std::min(1.0, double(FLAGS_clusterconfig_max_illegal)));
  Config.Independence = std::max(0.0, std::min(1.0, double(FLAGS_clusterconfig_independence)));
  Config.Confidence = std::max(0.0, std::min(1.0, double(FLAGS_clusterconfig_confidence)));
  // Set additional parameters from config file if specified.
  if (!FLAGS_configfile.empty()) {
    tesseract::ParamUtils::ReadParamsFile(
        FLAGS_configfile.c_str(), tesseract::SET_PARAM_CONSTRAINT_NON_INIT_ONLY, ccutil.params());
  }
}