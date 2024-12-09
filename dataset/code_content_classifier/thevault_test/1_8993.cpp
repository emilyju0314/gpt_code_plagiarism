static bool checkAttributeNumArgs(Sema &S, const ParsedAttr &AL, unsigned Num) {
  return checkAttributeNumArgsImpl(S, AL, Num,
                                   diag::err_attribute_wrong_number_arguments,
                                   std::not_equal_to<unsigned>());
}