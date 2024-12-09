void LinearProgrammingConstraint::CreateLpFromConstraintManager() {
  // Fill integer_lp_.
  integer_lp_.clear();
  infinity_norms_.clear();
  constraint_manager_.SetParameters(sat_parameters_);
  const auto& all_constraints = constraint_manager_.AllConstraints();
  for (const auto index : constraint_manager_.LpConstraints()) {
    const LinearConstraint& ct = all_constraints[index];
    integer_lp_.push_back(LinearConstraintInternal());
    LinearConstraintInternal& new_ct = integer_lp_.back();
    new_ct.lb = ct.lb;
    new_ct.ub = ct.ub;
    const int size = ct.vars.size();
    IntegerValue infinity_norm(0);
    if (ct.lb > kMinIntegerValue) {
      infinity_norm = std::max(infinity_norm, IntTypeAbs(ct.lb));
    }
    if (ct.ub < kMaxIntegerValue) {
      infinity_norm = std::max(infinity_norm, IntTypeAbs(ct.ub));
    }
    for (int i = 0; i < size; ++i) {
      // We only use positive variable inside this class.
      IntegerVariable var = ct.vars[i];
      IntegerValue coeff = ct.coeffs[i];
      if (!VariableIsPositive(var)) {
        var = NegationOf(var);
        coeff = -coeff;
      }
      infinity_norm = std::max(infinity_norm, IntTypeAbs(coeff));
      new_ct.terms.push_back({GetOrCreateMirrorVariable(var), coeff});
    }
    infinity_norms_.push_back(infinity_norm);

    // Important to keep lp_data_ "clean".
    std::sort(new_ct.terms.begin(), new_ct.terms.end());
  }

  // Copy the integer_lp_ into lp_data_.
  lp_data_.Clear();
  for (int i = 0; i < integer_variables_.size(); ++i) {
    CHECK_EQ(glop::ColIndex(i), lp_data_.CreateNewVariable());
  }
  for (const auto entry : integer_objective_) {
    lp_data_.SetObjectiveCoefficient(entry.first, ToDouble(entry.second));
  }
  for (const LinearConstraintInternal& ct : integer_lp_) {
    const ConstraintIndex row = lp_data_.CreateNewConstraint();
    lp_data_.SetConstraintBounds(row, ToDouble(ct.lb), ToDouble(ct.ub));
    for (const auto& term : ct.terms) {
      lp_data_.SetCoefficient(row, term.first, ToDouble(term.second));
    }
  }

  // Scale lp_data_.
  scaler_.Clear();
  Scale(&lp_data_, &scaler_, glop::GlopParameters::DEFAULT);
  lp_data_.ScaleObjective();

  // ScaleBounds() looks at both the constraints and variable bounds, so we
  // initialize the LP variable bounds before scaling them.
  //
  // TODO(user): As part of the scaling, we may also want to shift the initial
  // variable bounds so that each variable contain the value zero in their
  // domain. Maybe just once and for all at the beginning.
  bound_scaling_factor_ = 1.0;
  UpdateBoundsOfLpVariables();
  bound_scaling_factor_ = lp_data_.ScaleBounds();

  lp_data_.NotifyThatColumnsAreClean();
  lp_data_.AddSlackVariablesWhereNecessary(false);
  VLOG(1) << "LP relaxation: " << lp_data_.GetDimensionString() << ". "
          << constraint_manager_.AllConstraints().size()
          << " Managed constraints.";
}