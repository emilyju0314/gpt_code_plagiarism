IntegerValue LinearProgrammingConstraint::GetImpliedLowerBound(
    const LinearConstraint& terms) const {
  IntegerValue lower_bound(0);
  const int size = terms.vars.size();
  for (int i = 0; i < size; ++i) {
    const IntegerVariable var = terms.vars[i];
    const IntegerValue coeff = terms.coeffs[i];
    CHECK_NE(coeff, 0);
    const IntegerValue bound = coeff > 0 ? integer_trail_->LowerBound(var)
                                         : integer_trail_->UpperBound(var);
    if (!AddProductTo(bound, coeff, &lower_bound)) return kMinIntegerValue;
  }
  return lower_bound;
}