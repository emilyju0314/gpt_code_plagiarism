XGetopt(int const argc, char **&argv, std::string const &shortopts, csmap helpstrings_ = csmap())
      : optind(0), optarg(),                                     // empty string
        cmd_line_args(argv + 1, argv + argc), longopts(csmap()), // empty
        vshortopts_hasarg(std::map<char, bool>()), vshortopts(decompose_shortopts(shortopts)),
        helpstrings(std::move(helpstrings_)) {
    match_args_to_options();
  }