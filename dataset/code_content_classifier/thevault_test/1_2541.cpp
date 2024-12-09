std::shared_ptr<Expression> Expression::parse(unsigned const number_of_variables,
                                              Variable_Map const &variable_map,
                                              Unit const &expected_units,
                                              string const &expected_units_text,
                                              Token_Stream &tokens) {
  // No index in the variable map can be greater than or equal to the number of
  // variables.

  // The top expression is the or expression, which we anticipate will be useful
  // for piecewise functions.

  std::shared_ptr<Expression> Result = parse_or(number_of_variables, variable_map, tokens);
  while (tokens.lookahead().text() == "|") {
    tokens.shift();
    Result = std::make_shared<Or_Expression>(Result,
                                             parse_or(number_of_variables, variable_map, tokens));
  }
  if (unit_expressions_are_required() || !is_compatible(Result->units(), dimensionless)) {
    tokens.check_semantics(is_compatible(Result->units(), expected_units),
                           ("expected units of " + expected_units_text).c_str());
  }
  return Result;
}