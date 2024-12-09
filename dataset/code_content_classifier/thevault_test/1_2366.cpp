std::string XGetopt::display_help(std::string const &appName) const {
  Require(appName.size() > 0);

  // Build the output string starting with an empty ostringstream.
  std::ostringstream msg;
  msg << "\nUsage:"
      << "\n  " << appName << " [options]"
      << "\n\nOptions without arguments:\n";

  if (longopts.size() > 0) {
    // find the longest longopt string:
    // size_t max_len = std::max_element(
    //     longopts.begin(), longopts.end(),
    //     strlenComparator(vshortopts_hasarg) )->second.size();

    // find the longest longopt string, excluding args with options:
    size_t max_len(0);
    for (auto const &it : longopts) {
      bool hasarg = vshortopts_hasarg.find(it.first)->second;
      if (!hasarg && it.second.length() > max_len)
        max_len = it.second.length();
    }

    // show options w/o arguments first
    for (auto const &it : longopts) {
      char shortopt = it.first;
      std::string longopt = it.second;
      bool hasarg = vshortopts_hasarg.find(shortopt)->second;
      std::string helpmsg("");

      if (helpstrings.count(shortopt) > 0)
        helpmsg = helpstrings.find(shortopt)->second;

      // pad longopt so that they are all of the same length.
      if (longopt.length() < max_len)
        longopt = longopt + std::string(max_len - longopt.length(), ' ');

      if (!hasarg)
        msg << "   -" << shortopt << " | --" << longopt << " : " << helpmsg << "\n";
    }

    // find the longest longopt string, including args with options:
    max_len = 0;
    for (auto const &it : longopts) {
      bool hasarg = vshortopts_hasarg.find(it.first)->second;
      if (hasarg && it.second.length() > max_len)
        max_len = it.second.length();
    }

    // show options that require arguments
    msg << "\nOptions requiring arguments:\n";
    for (auto const &it : longopts) {
      char shortopt = it.first;
      std::string longopt = it.second;
      bool hasarg = vshortopts_hasarg.find(shortopt)->second;
      std::string helpmsg("");

      if (helpstrings.count(shortopt) > 0)
        helpmsg = helpstrings.find(shortopt)->second;

      if (hasarg) {
        // format the help string by replacing '\n' with '\n'+hanging_indent.
        std::string hanging_indent(21 + max_len, ' ');
        std::string formatted_help_msg(helpmsg);
        size_t index(0);
        while (true) {
          // find first line break.
          index = formatted_help_msg.find('\n', index);
          if (index == std::string::npos)
            break;
          // add hanging indent.
          formatted_help_msg.insert(++index, hanging_indent);
          // Advance index forward so the next iteration doesn't pick it up as well.
          index += 21;
        }

        msg << "   -" << shortopt << " | --" << longopt << " <value>"
            << std::string(max_len - longopt.length(), ' ') << " : " << formatted_help_msg << "\n";
      }
    }
  } else {
    // show options w/o arguments first

    for (char shortopt : vshortopts) {
      if (shortopt == ':')
        continue;
      bool hasarg = vshortopts_hasarg.find(shortopt)->second;
      std::string helpmsg("");
      if (helpstrings.count(shortopt) > 0)
        helpmsg = helpstrings.find(shortopt)->second;

      if (!hasarg)
        msg << "   -" << shortopt << " : " << helpmsg << "\n";
    }

    // show options that require arguments

    msg << "\nOptions requiring arguments:\n";
    for (char shortopt : vshortopts) {
      bool hasarg = vshortopts_hasarg.find(shortopt)->second;
      std::string helpmsg("");
      if (helpstrings.count(shortopt) > 0)
        helpmsg = helpstrings.find(shortopt)->second;

      if (hasarg) {
        // format the help string by replacing '\n' with '\n'+hanging_indent.
        std::string hanging_indent(16, ' ');
        std::string formatted_help_msg(helpmsg);
        size_t index(0);
        while (true) {
          // find first line break.
          index = formatted_help_msg.find('\n', index);
          if (index == std::string::npos)
            break;
          // add hanging indent.
          formatted_help_msg.insert(++index, hanging_indent);
          // Advance index forward so the next iteration doesn't pick it up as well.
          index += hanging_indent.size();
        }

        msg << "   -" << shortopt << " <value>"
            << " : " << formatted_help_msg << std::endl;
      }
    }
  }

  msg << "   -- : Stop processing any further arguments." << std::endl;
  return msg.str();
}