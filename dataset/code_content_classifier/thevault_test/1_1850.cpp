void LinearConstraintManager::Add(const LinearConstraint& ct) {
  LinearConstraint canonicalized = ct;
  const Terms terms = CanonicalizeConstraintAndGetTerms(&canonicalized);
  CHECK(!terms.empty());

  if (gtl::ContainsKey(equiv_constraints_, terms)) {
    const ConstraintIndex index(
        gtl::FindOrDieNoPrint(equiv_constraints_, terms));
    if (canonicalized.lb > constraints_[index].lb) {
      if (constraint_is_in_lp_[index]) {
        some_lp_constraint_bounds_changed_ = true;
      }
      constraints_[index].lb = canonicalized.lb;
    }
    if (canonicalized.ub < constraints_[index].ub) {
      if (constraint_is_in_lp_[index]) {
        some_lp_constraint_bounds_changed_ = true;
      }
      constraints_[index].ub = canonicalized.ub;
    }
    ++num_merged_constraints_;
  } else {
    constraint_l2_norms_.push_back(ComputeL2Norm(canonicalized));
    equiv_constraints_[terms] = constraints_.size();
    constraint_is_in_lp_.push_back(false);
    constraint_is_cut_.push_back(false);
    constraint_inactive_count_.push_back(0);
    constraint_permanently_removed_.push_back(false);
    constraints_.push_back(std::move(canonicalized));
  }
}