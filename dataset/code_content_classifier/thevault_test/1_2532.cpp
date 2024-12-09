void add_debug_option(string const &option_name, unsigned const bit) {
  Require(bit != 0);         // corner case will fail
  Require(bit >= DEBUG_END); // can't redefine standard debug
  Require(is_bit(bit));

  if (extended_debug_option.find(option_name) != extended_debug_option.end()) {
    if (extended_debug_option[option_name] != bit) {
      throw std::invalid_argument("debug option redefined");
    }
    // else duplicate identical definition acceptable
  } else if (extended_debug_back_option.find(bit) != extended_debug_back_option.end()) {
    throw std::invalid_argument("bitflag already allocated");
  } else {
    extended_debug_option[option_name] = bit;
    extended_debug_back_option[bit] = option_name;
  }
}