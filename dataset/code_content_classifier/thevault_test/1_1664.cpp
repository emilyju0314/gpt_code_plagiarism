static bool
validateSwiftFunctionName(Sema &S, const ParsedAttr &AL, SourceLocation Loc,
                          StringRef Name, unsigned &SwiftParamCount,
                          bool &IsSingleParamInit) {
  SwiftParamCount = 0;
  IsSingleParamInit = false;

  // Check whether this will be mapped to a getter or setter of a property.
  bool IsGetter = false, IsSetter = false;
  if (Name.startswith("getter:")) {
    IsGetter = true;
    Name = Name.substr(7);
  } else if (Name.startswith("setter:")) {
    IsSetter = true;
    Name = Name.substr(7);
  }

  if (Name.back() != ')') {
    S.Diag(Loc, diag::warn_attr_swift_name_function) << AL;
    return false;
  }

  bool IsMember = false;
  StringRef ContextName, BaseName, Parameters;

  std::tie(BaseName, Parameters) = Name.split('(');

  // Split at the first '.', if it exists, which separates the context name
  // from the base name.
  std::tie(ContextName, BaseName) = BaseName.split('.');
  if (BaseName.empty()) {
    BaseName = ContextName;
    ContextName = StringRef();
  } else if (ContextName.empty() || !isValidIdentifier(ContextName)) {
    S.Diag(Loc, diag::warn_attr_swift_name_invalid_identifier)
        << AL << /*context*/ 1;
    return false;
  } else {
    IsMember = true;
  }

  if (!isValidIdentifier(BaseName) || BaseName == "_") {
    S.Diag(Loc, diag::warn_attr_swift_name_invalid_identifier)
        << AL << /*basename*/ 0;
    return false;
  }

  bool IsSubscript = BaseName == "subscript";
  // A subscript accessor must be a getter or setter.
  if (IsSubscript && !IsGetter && !IsSetter) {
    S.Diag(Loc, diag::warn_attr_swift_name_subscript_invalid_parameter)
        << AL << /* getter or setter */ 0;
    return false;
  }

  if (Parameters.empty()) {
    S.Diag(Loc, diag::warn_attr_swift_name_missing_parameters) << AL;
    return false;
  }

  assert(Parameters.back() == ')' && "expected ')'");
  Parameters = Parameters.drop_back(); // ')'

  if (Parameters.empty()) {
    // Setters and subscripts must have at least one parameter.
    if (IsSubscript) {
      S.Diag(Loc, diag::warn_attr_swift_name_subscript_invalid_parameter)
          << AL << /* have at least one parameter */1;
      return false;
    }

    if (IsSetter) {
      S.Diag(Loc, diag::warn_attr_swift_name_setter_parameters) << AL;
      return false;
    }

    return true;
  }

  if (Parameters.back() != ':') {
    S.Diag(Loc, diag::warn_attr_swift_name_function) << AL;
    return false;
  }

  StringRef CurrentParam;
  llvm::Optional<unsigned> SelfLocation;
  unsigned NewValueCount = 0;
  llvm::Optional<unsigned> NewValueLocation;
  do {
    std::tie(CurrentParam, Parameters) = Parameters.split(':');

    if (!isValidIdentifier(CurrentParam)) {
      S.Diag(Loc, diag::warn_attr_swift_name_invalid_identifier)
          << AL << /*parameter*/2;
      return false;
    }

    if (IsMember && CurrentParam == "self") {
      // "self" indicates the "self" argument for a member.

      // More than one "self"?
      if (SelfLocation) {
        S.Diag(Loc, diag::warn_attr_swift_name_multiple_selfs) << AL;
        return false;
      }

      // The "self" location is the current parameter.
      SelfLocation = SwiftParamCount;
    } else if (CurrentParam == "newValue") {
      // "newValue" indicates the "newValue" argument for a setter.

      // There should only be one 'newValue', but it's only significant for
      // subscript accessors, so don't error right away.
      ++NewValueCount;

      NewValueLocation = SwiftParamCount;
    }

    ++SwiftParamCount;
  } while (!Parameters.empty());

  // Only instance subscripts are currently supported.
  if (IsSubscript && !SelfLocation) {
    S.Diag(Loc, diag::warn_attr_swift_name_subscript_invalid_parameter)
        << AL << /*have a 'self:' parameter*/2;
    return false;
  }

  IsSingleParamInit =
        SwiftParamCount == 1 && BaseName == "init" && CurrentParam != "_";

  // Check the number of parameters for a getter/setter.
  if (IsGetter || IsSetter) {
    // Setters have one parameter for the new value.
    unsigned NumExpectedParams = IsGetter ? 0 : 1;
    unsigned ParamDiag =
        IsGetter ? diag::warn_attr_swift_name_getter_parameters
                 : diag::warn_attr_swift_name_setter_parameters;

    // Instance methods have one parameter for "self".
    if (SelfLocation)
      ++NumExpectedParams;

    // Subscripts may have additional parameters beyond the expected params for
    // the index.
    if (IsSubscript) {
      if (SwiftParamCount < NumExpectedParams) {
        S.Diag(Loc, ParamDiag) << AL;
        return false;
      }

      // A subscript setter must explicitly label its newValue parameter to
      // distinguish it from index parameters.
      if (IsSetter) {
        if (!NewValueLocation) {
          S.Diag(Loc, diag::warn_attr_swift_name_subscript_setter_no_newValue)
              << AL;
          return false;
        }
        if (NewValueCount > 1) {
          S.Diag(Loc, diag::warn_attr_swift_name_subscript_setter_multiple_newValues)
              << AL;
          return false;
        }
      } else {
        // Subscript getters should have no 'newValue:' parameter.
        if (NewValueLocation) {
          S.Diag(Loc, diag::warn_attr_swift_name_subscript_getter_newValue)
              << AL;
          return false;
        }
      }
    } else {
      // Property accessors must have exactly the number of expected params.
      if (SwiftParamCount != NumExpectedParams) {
        S.Diag(Loc, ParamDiag) << AL;
        return false;
      }
    }
  }

  return true;
}