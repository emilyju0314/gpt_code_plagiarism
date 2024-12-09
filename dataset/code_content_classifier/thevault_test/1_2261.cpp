Err ReadLocation(const Command& cmd, const char* command_name, Location* location,
                 uint64_t* location_size) {
  *location_size = 0;
  if (cmd.args().size() != 1)
    return Err("%s requires exactly one argument specifying a location.", command_name);

  // We need to check the type of the parsed input location so parse and resolve in two steps.
  std::vector<InputLocation> input_locations;
  if (Err err = ParseLocalInputLocation(cmd.frame(), cmd.args()[0], &input_locations);
      err.has_error())
    return err;
  FXL_DCHECK(!input_locations.empty());

  if (Err err = ResolveUniqueInputLocation(cmd.target()->GetProcess()->GetSymbols(),
                                           input_locations, true, location);
      err.has_error())
    return err;

  // Some symbols can give us sizes. All input locations will have the same type (matching the user
  // input type).
  if (input_locations[0].type == InputLocation::Type::kName) {
    if (location->symbol()) {
      if (const CodeBlock* block = location->symbol().Get()->AsCodeBlock()) {
        *location_size = block->GetFullRange(location->symbol_context()).size();
      }
    }
  }
  return Err();
}