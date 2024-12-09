std::shared_ptr<Expression> Expression::parse(unsigned const number_of_variables,
                                              Variable_Map const &variable_map,
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
  return Result;
}