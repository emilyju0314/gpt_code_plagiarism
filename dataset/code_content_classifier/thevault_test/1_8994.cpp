static bool checkAttributeAtLeastNumArgs(Sema &S, const ParsedAttr &AL,
                                         unsigned Num) {
  return checkAttributeNumArgsImpl(S, AL, Num,
                                   diag::err_attribute_too_few_arguments,
                                   std::less<unsigned>());
}