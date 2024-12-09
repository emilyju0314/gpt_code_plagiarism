void XGetopt::match_args_to_options() {
  // Loop over all command line arguments
  for (size_t iarg = 0; iarg < cmd_line_args.size(); ++iarg) {
    // stop processing command line arguments
    if (cmd_line_args[iarg] == std::string("--"))
      return;

    // try to match a short option ('-a')
    if (cmd_line_args[iarg].size() == 2) {
      char const shortarg = cmd_line_args[iarg][1];
      if (std::find(vshortopts.begin(), vshortopts.end(), shortarg) != vshortopts.end()) {
        matched_arguments.push_back(cmd_line_args[iarg][1]);
        if (vshortopts_hasarg[shortarg]) {
          bool cmd_line_option_requires_value(iarg + 1 < cmd_line_args.size());
          Insist(cmd_line_option_requires_value, std::string("The command argument '-") + shortarg +
                                                     "' expected a value to be provided.");
          matched_arguments_values[shortarg] = cmd_line_args[++iarg];
        }
      } else {
        unmatched_arguments.push_back(cmd_line_args[iarg]);
      }
    }

    // consider string-based optons here.
    else if (cmd_line_args[iarg].substr(0, 2) == std::string("--")) {
      // The command line argument w/o the leading '--'
      std::string const longarg = cmd_line_args[iarg].substr(2, cmd_line_args[iarg].size());
      char shortarg('\0');

      // Find long argument match and its associated shortarg key.
      for (auto const &it : longopts) {
        if (it.second == longarg) {
          shortarg = it.first;

          // Save the match and associated data.
          matched_arguments.push_back(shortarg);
          if (vshortopts_hasarg[shortarg]) {
            bool cmd_line_option_requires_value(iarg + 1 < cmd_line_args.size());
            Insist(cmd_line_option_requires_value, std::string("The command argument '--") +
                                                       longarg +
                                                       "' expected a value to be provided.");
            matched_arguments_values[shortarg] = cmd_line_args[++iarg];
          }
          break;
        }
      }
      // if we get here, there was an argument that starts with '--' but does not match a registered
      // option:
      if (shortarg == '\0')
        unmatched_arguments.push_back(cmd_line_args[iarg]);
    }

    // Provided argument is not '[-][A-z]' or does not start with '--' or is not a value string
    // associated with a preceeding argument.
    else {
      unmatched_arguments.push_back(cmd_line_args[iarg]);
    }
  }
  return;
}