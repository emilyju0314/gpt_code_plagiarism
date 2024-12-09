void ModuleSymbolsImpl::ResolveLineInputLocationForFile(const SymbolContext& symbol_context,
                                                        const std::string& canonical_file,
                                                        int line_number,
                                                        const ResolveOptions& options,
                                                        std::vector<Location>* output) const {
  const std::vector<unsigned>* units = index_.FindFileUnitIndices(canonical_file);
  if (!units)
    return;

  std::vector<LineMatch> matches;
  for (unsigned index : *units) {
    llvm::DWARFUnit* unit = context_->getUnitAtIndex(index);
    LineTableImpl line_table(context_.get(), unit);

    // Complication 1 above: find all matches for this line in the unit.
    std::vector<LineMatch> unit_matches =
        GetAllLineTableMatchesInUnit(line_table, canonical_file, line_number);

    matches.insert(matches.end(), unit_matches.begin(), unit_matches.end());
  }

  if (matches.empty())
    return;

  // Complications 2 & 3 above: Get all instances of the best match only with a max of one per
  // function. The best match is the one with the lowest line number (found matches should all be
  // bigger than the input line, so this will be the closest).
  for (const LineMatch& match : GetBestLineMatches(matches)) {
    uint64_t abs_addr = symbol_context.RelativeToAbsolute(match.address);
    if (options.symbolize)
      output->push_back(LocationForAddress(symbol_context, abs_addr, options, nullptr));
    else
      output->push_back(Location(Location::State::kAddress, abs_addr));
  }
}