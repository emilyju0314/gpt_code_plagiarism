void ParseArguments(int *argc, char ***argv) {
  std::string usage;
  if (*argc) {
    usage += (*argv)[0];
    usage += " -v | --version | ";
    usage += (*argv)[0];
  }
  usage += " [.tr files ...]";
  tesseract::ParseCommandLineFlags(usage.c_str(), argc, argv, true);
}