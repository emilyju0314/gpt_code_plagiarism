Err ParseListLocation(const TargetSymbols* target_symbols, const ProcessSymbols* process_symbols,
                      const Frame* frame, const std::string& arg, FileLine* file_line) {
  // One arg = normal location (ParseInputLocation can handle null frames).
  std::vector<InputLocation> input_locations;
  if (Err err = ParseLocalInputLocation(frame, arg, &input_locations); err.has_error())
    return err;
  FXL_DCHECK(!input_locations.empty());

  // When a file/line is given, we don't actually want to look up the symbol information, just match
  // file names. Then we can find the requested line in the file regardless of whether there's a
  // symbol for it.
  //
  // We can assume file name inputs will only resolve to one InputLocation. Multiple outputs only
  // happens for symbolic names.
  if (input_locations.size() == 1u && input_locations[0].type == InputLocation::Type::kLine)
    return CanonicalizeFile(target_symbols, input_locations[0].line, file_line);

  if (!process_symbols) {
    // This could be enhanced to support listing when there is no running process but there are
    // symbols loaded (the TargetSymbols) should have file names and such). This isn't a big
    // use-case currently and it requires different resolution machinery, so skip for now.
    return Err("Can't list without a currently running process.");
  }

  std::vector<Location> locations;
  if (Err err = ResolveInputLocations(process_symbols, input_locations, true, &locations);
      err.has_error())
    return err;

  // Inlined functions might resolve to many locations, but only one file/line, or there could be
  // multiple file name matches. Find the unique ones.
  std::set<FileLine> matches;
  for (const auto& location : locations) {
    if (location.file_line().is_valid())
      matches.insert(location.file_line());
  }

  // Check for no matches after extracting file/line info in case some matches lacked file/line
  // information.
  if (matches.empty()) {
    if (!locations.empty())
      return Err("The match(es) for this had no line information.");

    // The type won't vary if there are different input locations that were resolved.
    switch (input_locations[0].type) {
      case InputLocation::Type::kLine:
        return Err("There are no files matching \"%s\".", input_locations[0].line.file().c_str());
      case InputLocation::Type::kName:
        return Err("There are no symbols matching \"%s\".",
                   FormatInputLocation(input_locations[0]).AsString().c_str());
      case InputLocation::Type::kAddress:
      case InputLocation::Type::kNone:
      default:
        // Addresses will always be found.
        FXL_NOTREACHED();
        return Err("Internal error.");
    }
  }

  if (matches.size() > 1) {
    std::string msg = "There are multiple matches for this symbol:\n";
    for (const auto& match : matches) {
      msg +=
          fxl::StringPrintf(" %s %s:%d\n", GetBullet().c_str(), match.file().c_str(), match.line());
    }
    return Err(msg);
  }

  *file_line = *matches.begin();
  return Err();
}