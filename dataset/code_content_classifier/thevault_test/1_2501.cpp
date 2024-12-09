XGetopt(int const argc, char **&argv, csmap const &longopts_, csmap helpstrings_ = csmap())
      : optind(0), optarg(), // empty string
        cmd_line_args(argv + 1, argv + argc), longopts(store_longopts(longopts_)),
        vshortopts_hasarg(std::map<char, bool>()), vshortopts(decompose_longopts(longopts_)),
        helpstrings(std::move(helpstrings_)) {
    match_args_to_options();
  }