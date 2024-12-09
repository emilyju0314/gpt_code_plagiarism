void LinearConstraintManager::AddCut(
    const LinearConstraint& ct, std::string type_name,
    const gtl::ITIVector<IntegerVariable, double>& lp_solution) {
  if (ct.vars.empty()) return;

  const double activity = ComputeActivity(ct, lp_solution);
  const double violation =
      std::max(activity - ToDouble(ct.ub), ToDouble(ct.lb) - activity);
  const double l2_norm = ComputeL2Norm(ct);

  // Only add cut with sufficient efficacy.
  if (violation / l2_norm < 1e-5) return;

  Add(ct);
  constraint_is_cut_.back() = true;
  num_cuts_++;
  type_to_num_cuts_[type_name]++;

  VLOG(2) << "Cut '" << type_name << "'"
          << " size=" << ct.vars.size()
          << " max_magnitude=" << ComputeInfinityNorm(ct) << " norm=" << l2_norm
          << " violation=" << violation << " eff=" << violation / l2_norm;
}