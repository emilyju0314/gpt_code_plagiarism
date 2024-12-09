inline strings_internal::PairFormatterImpl<strings_internal::AlphaNumFormatterImpl,
                                           strings_internal::AlphaNumFormatterImpl>
PairFormatter(std::string_view sep) {
  return PairFormatter(AlphaNumFormatter(), sep, AlphaNumFormatter());
}