void LinearProgrammingConstraint::AdjustNewLinearConstraint(
    std::vector<std::pair<glop::RowIndex, IntegerValue>>* integer_multipliers,
    gtl::ITIVector<ColIndex, IntegerValue>* dense_terms,
    IntegerValue* upper_bound) const {
  const IntegerValue kMaxWantedCoeff(1e18);
  for (std::pair<RowIndex, IntegerValue>& term : *integer_multipliers) {
    const RowIndex row = term.first;
    const IntegerValue multiplier = term.second;
    if (multiplier == 0) continue;

    // We will only allow change of the form "multiplier += to_add" with to_add
    // in [-negative_limit, positive_limit].
    IntegerValue negative_limit = kMaxWantedCoeff;
    IntegerValue positive_limit = kMaxWantedCoeff;

    // Make sure we never change the sign of the multiplier, except if the
    // row is an equality in which case we don't care.
    if (integer_lp_[row.value()].ub != integer_lp_[row.value()].lb) {
      if (multiplier > 0) {
        negative_limit = std::min(negative_limit, multiplier);
      } else {
        positive_limit = std::min(positive_limit, -multiplier);
      }
    }

    // Make sure upper_bound + to_add * row_bound never overflow.
    const IntegerValue row_bound = multiplier > 0 ? integer_lp_[row.value()].ub
                                                  : integer_lp_[row.value()].lb;
    if (row_bound != 0) {
      const IntegerValue limit1 = FloorRatio(
          std::max(IntegerValue(0), kMaxWantedCoeff - IntTypeAbs(*upper_bound)),
          IntTypeAbs(row_bound));
      const IntegerValue limit2 =
          FloorRatio(kMaxWantedCoeff, IntTypeAbs(row_bound));
      if (*upper_bound > 0 == row_bound > 0) {  // Same sign.
        positive_limit = std::min(positive_limit, limit1);
        negative_limit = std::min(negative_limit, limit2);
      } else {
        negative_limit = std::min(negative_limit, limit1);
        positive_limit = std::min(positive_limit, limit2);
      }
    }

    // If we add the row to the dense_terms, diff will indicate by how much
    // |upper_bound - ImpliedLB(dense_terms)| will change. That correspond to
    // increasing the multiplier by 1.
    IntegerValue positive_diff = row_bound;
    IntegerValue negative_diff = row_bound;

    // TODO(user): we could relax a bit some of the condition and allow a sign
    // change. It is just trickier to compute the diff when we allow such
    // changes.
    for (const auto entry : integer_lp_[row.value()].terms) {
      const ColIndex col = entry.first;
      const IntegerValue coeff = entry.second;
      CHECK_NE(coeff, 0);

      // Moving a variable away from zero seems to improve the bound even
      // if it reduces the number of non-zero. Note that this is because of
      // this that positive_diff and negative_diff are not the same.
      const IntegerValue current = (*dense_terms)[col];
      if (current == 0) {
        const IntegerValue overflow_limit(
            FloorRatio(kMaxWantedCoeff, IntTypeAbs(coeff)));
        positive_limit = std::min(positive_limit, overflow_limit);
        negative_limit = std::min(negative_limit, overflow_limit);
        const IntegerVariable var = integer_variables_[col.value()];
        if (coeff > 0) {
          positive_diff -= coeff * integer_trail_->LowerBound(var);
          negative_diff -= coeff * integer_trail_->UpperBound(var);
        } else {
          positive_diff -= coeff * integer_trail_->UpperBound(var);
          negative_diff -= coeff * integer_trail_->LowerBound(var);
        }
        continue;
      }

      // We don't want to change the sign of current or to have an overflow.
      IntegerValue before_sign_change(
          FloorRatio(IntTypeAbs(current), IntTypeAbs(coeff)));

      // If the variable is fixed, we don't actually care about changing the
      // sign.
      const IntegerVariable var = integer_variables_[col.value()];
      if (integer_trail_->LowerBound(var) == integer_trail_->UpperBound(var)) {
        before_sign_change = kMaxWantedCoeff;
      }

      const IntegerValue overflow_limit(
          FloorRatio(kMaxWantedCoeff - IntTypeAbs(current), IntTypeAbs(coeff)));
      if (current > 0 == coeff > 0) {  // Same sign.
        negative_limit = std::min(negative_limit, before_sign_change);
        positive_limit = std::min(positive_limit, overflow_limit);
      } else {
        negative_limit = std::min(negative_limit, overflow_limit);
        positive_limit = std::min(positive_limit, before_sign_change);
      }

      // This is how diff change.
      const IntegerValue implied = current > 0
                                       ? integer_trail_->LowerBound(var)
                                       : integer_trail_->UpperBound(var);

      positive_diff -= coeff * implied;
      negative_diff -= coeff * implied;
    }

    // Only add a multiple of this row if it tighten the final constraint.
    IntegerValue to_add(0);
    if (positive_diff < 0 && positive_limit > 0) {
      to_add = positive_limit;
    }
    if (negative_diff > 0 && negative_limit > 0) {
      // Pick this if it is better than the positive sign.
      if (to_add == 0 || IntTypeAbs(negative_limit * negative_diff) >
                             IntTypeAbs(positive_limit * positive_diff)) {
        to_add = -negative_limit;
      }
    }
    if (to_add != 0) {
      term.second += to_add;
      *upper_bound += to_add * row_bound;
      for (const auto entry : integer_lp_[row.value()].terms) {
        const ColIndex col = entry.first;
        const IntegerValue coeff = entry.second;
        (*dense_terms)[col] += to_add * coeff;
      }
    }
  }
}