std::shared_ptr<Quadrature> General_Octant_Quadrature::parse(Token_Stream &tokens) {
  Token token = tokens.shift();
  tokens.check_syntax(token.text() == "sn order", "expected sn order");

  unsigned sn_order = parse_positive_integer(tokens);

  token = tokens.shift();
  tokens.check_syntax(token.text() == "number of ordinates", "expected number of ordinates");

  unsigned Num = parse_positive_integer(tokens);

  token = tokens.shift();
  tokens.check_syntax(token.text() == "number of levels", "expected number of levels");

  unsigned number_of_levels = parse_unsigned_integer(tokens);

  token = tokens.lookahead();

  Quadrature_Class quadrature_class = OCTANT_QUADRATURE;
  if (token.text() == "quadrature class") {
    tokens.shift();
    token = tokens.shift();
    if (token.text() == "triangle") {
      quadrature_class = TRIANGLE_QUADRATURE;
    } else if (token.text() == "square") {
      quadrature_class = SQUARE_QUADRATURE;
    } else {
      tokens.check_semantics(token.text() == "octant", "unrecognized quadrature class");
    }
  }

  vector<double> mu(Num), eta(Num), xi(Num), wt(Num);

  for (unsigned i = 0; i < Num; ++i) {
    mu[i] = parse_real(tokens);
    eta[i] = parse_real(tokens);
    xi[i] = parse_real(tokens);
    wt[i] = parse_real(tokens);
  }

  tokens.check_syntax(tokens.shift().type() == END, "missing end?");

  return std::shared_ptr<Quadrature>(
      new General_Octant_Quadrature(sn_order, mu, eta, xi, wt, number_of_levels, quadrature_class));
}