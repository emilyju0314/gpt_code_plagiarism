bool LinearProgrammingConstraint::ExactLpReasonning() {
  // Clear old reason and deductions.
  integer_reason_.clear();
  deductions_.clear();
  deductions_reason_.clear();

  // The row multipliers will be the negation of the LP duals.
  //
  // TODO(user): Provide and use a sparse API in Glop to get the duals.
  const RowIndex num_rows = simplex_.GetProblemNumRows();
  glop::DenseColumn lp_multipliers(num_rows);
  for (RowIndex row(0); row < num_rows; ++row) {
    lp_multipliers[row] = -simplex_.GetDualValue(row);
  }

  Fractional scaling;
  std::vector<std::pair<RowIndex, IntegerValue>> integer_multipliers =
      ScaleLpMultiplier(/*take_objective_into_account=*/true,
                        /*use_constraint_status=*/false, lp_multipliers,
                        &scaling);

  gtl::ITIVector<ColIndex, IntegerValue> reduced_costs;
  IntegerValue rc_ub;
  CHECK(ComputeNewLinearConstraint(
      /*use_constraint_status=*/false, integer_multipliers, &reduced_costs,
      &rc_ub));

  // The "objective constraint" behave like if the unscaled cp multiplier was
  // 1.0, so we will multiply it by this number and add it to reduced_costs.
  const IntegerValue obj_scale(std::round(scaling));
  if (obj_scale == 0) {
    VLOG(1) << "Overflow during exact LP reasoning. scaling=" << scaling;
    return true;
  }
  CHECK(AddLinearExpressionMultiple(obj_scale, integer_objective_,
                                    &reduced_costs));

  AdjustNewLinearConstraint(&integer_multipliers, &reduced_costs, &rc_ub);

  // Create the IntegerSumLE that will allow to propagate the objective and more
  // generally do the reduced cost fixing.
  LinearConstraint new_constraint =
      ConvertToLinearConstraint(reduced_costs, rc_ub);
  new_constraint.vars.push_back(objective_cp_);
  new_constraint.coeffs.push_back(-obj_scale);
  DivideByGCD(&new_constraint);

  // Check for possible overflow in IntegerSumLE::Propagate().
  if (PossibleOverflow(new_constraint)) {
    VLOG(2) << "Overflow during exact LP reasoning.";
    return true;
  }

  IntegerSumLE* cp_constraint =
      new IntegerSumLE({}, new_constraint.vars, new_constraint.coeffs,
                       new_constraint.ub, model_);
  optimal_constraints_.emplace_back(cp_constraint);
  rev_optimal_constraints_size_ = optimal_constraints_.size();
  return cp_constraint->Propagate();
}