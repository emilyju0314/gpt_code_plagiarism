unsigned add_debug_option(string const &option_name) {
  if (extended_debug_option.find(option_name) != extended_debug_option.end()) {
    // option already exists; regard as benign
    return extended_debug_option[option_name];
  } else {
    while (available != 0 &&
           extended_debug_back_option.find(available) != extended_debug_back_option.end()) {
      available <<= 1U;
    }
    if (available == 0) {
      throw std::range_error("maximum debug options exceeded");
      // yeah, i know, if there are 4G debug options, someone has lost his
      // mind. Still.
    }
    extended_debug_option[option_name] = available;
    extended_debug_back_option[available] = option_name;
    return available;
  }
}