Expr * Parser::parseOperand()
{
  Token tok = gettok();
  Expr *expr = NULL;
  if /**/ (tok == tok_var_start || tok == tok_var_not_start) // Parse variable
    expr = parseVar(tok == tok_var_not_start);
  else if (tok == tok_input) // Parse input
    expr = parseInput();
  else if (tok == tok_str_length) // Length function
    expr = parseLengthFunction();
  
  return expr;
}