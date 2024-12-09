static bool checkAttributeAtMostNumArgs(Sema &S, const ParsedAttr &AL,
                                        unsigned Num) {
  return checkAttributeNumArgsImpl(S, AL, Num,
                                   diag::err_attribute_too_many_arguments,
                                   std::greater<unsigned>());
}