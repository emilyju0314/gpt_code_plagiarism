static bool handleCommonAttributeFeatures(Sema &S, Decl *D,
                                          const ParsedAttr &AL) {
  // Several attributes carry different semantics than the parsing requires, so
  // those are opted out of the common argument checks.
  //
  // We also bail on unknown and ignored attributes because those are handled
  // as part of the target-specific handling logic.
  if (AL.getKind() == ParsedAttr::UnknownAttribute)
    return false;
  // Check whether the attribute requires specific language extensions to be
  // enabled.
  if (!AL.diagnoseLangOpts(S))
    return true;
  // Check whether the attribute appertains to the given subject.
  if (!AL.diagnoseAppertainsTo(S, D))
    return true;
  if (AL.hasCustomParsing())
    return false;

  if (AL.getMinArgs() == AL.getMaxArgs()) {
    // If there are no optional arguments, then checking for the argument count
    // is trivial.
    if (!checkAttributeNumArgs(S, AL, AL.getMinArgs()))
      return true;
  } else {
    // There are optional arguments, so checking is slightly more involved.
    if (AL.getMinArgs() &&
        !checkAttributeAtLeastNumArgs(S, AL, AL.getMinArgs()))
      return true;
    else if (!AL.hasVariadicArg() && AL.getMaxArgs() &&
             !checkAttributeAtMostNumArgs(S, AL, AL.getMaxArgs()))
      return true;
  }

  if (S.CheckAttrTarget(AL))
    return true;

  return false;
}