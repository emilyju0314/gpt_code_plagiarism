void LinearProgrammingConstraint::SetImpliedLowerBoundReason(
    const LinearConstraint& terms, IntegerValue slack) {
  integer_reason_.clear();
  std::vector<IntegerValue> magnitudes;
  const int size = terms.vars.size();
  for (int i = 0; i < size; ++i) {
    const IntegerVariable var = terms.vars[i];
    const IntegerValue coeff = terms.coeffs[i];
    CHECK_NE(coeff, 0);
    if (coeff > 0) {
      magnitudes.push_back(coeff);
      integer_reason_.push_back(integer_trail_->LowerBoundAsLiteral(var));
    } else {
      magnitudes.push_back(-coeff);
      integer_reason_.push_back(integer_trail_->UpperBoundAsLiteral(var));
    }
  }
  CHECK_GE(slack, 0);
  if (slack > 0) {
    integer_trail_->RelaxLinearReason(slack, magnitudes, &integer_reason_);
  }
  integer_trail_->RemoveLevelZeroBounds(&integer_reason_);
}