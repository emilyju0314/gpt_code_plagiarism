double Expression::operator()(vector<double> const &x) const {
  Insist(x.size() > 0, std::string("Expression::operator() requires a non-zero length ") +
                           std::string("vector as an argument."));
  Require(x.size() == number_of_variables());
  return evaluate_(&x[0]);
}