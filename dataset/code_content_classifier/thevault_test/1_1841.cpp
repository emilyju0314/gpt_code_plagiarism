void ExtractEnforcementLiteralFromLinearConstraint(ConstraintProto* ct,
                                                   PresolveContext* context) {
  const LinearConstraintProto& arg = ct->linear();
  const int num_vars = arg.vars_size();
  int64 min_sum = 0;
  int64 max_sum = 0;
  for (int i = 0; i < num_vars; ++i) {
    const int ref = arg.vars(i);
    const int64 coeff = arg.coeffs(i);
    const int64 term_a = coeff * context->MinOf(ref);
    const int64 term_b = coeff * context->MaxOf(ref);
    min_sum += std::min(term_a, term_b);
    max_sum += std::max(term_a, term_b);
  }

  // We only deal with the case of a single bounded constraint. This is because
  // if a constraint has two non-trivial finite bounds, then there can be no
  // literal that will make the constraint always true.
  Domain rhs_domain = ReadDomainFromProto(ct->linear());
  const bool not_lower_bounded = min_sum >= rhs_domain.Min();
  const bool not_upper_bounded = max_sum <= rhs_domain.Max();
  if (not_lower_bounded == not_upper_bounded) return;

  // To avoid a quadratic loop, we will rewrite the linear expression at the
  // same time as we extract enforcement literals.
  int new_size = 0;
  LinearConstraintProto* mutable_arg = ct->mutable_linear();
  for (int i = 0; i < arg.vars_size(); ++i) {
    // Only work with binary variables.
    //
    // TODO(user,user): This could be generalized to non-binary variable
    // but that would require introducing the encoding "literal <=> integer
    // variable at is min/max" and using this literal in the enforcement list.
    // It is thus a bit more involved, and might not be as useful.
    const int ref = arg.vars(i);
    if (context->MinOf(ref) == 0 && context->MaxOf(ref) == 1) {
      const int64 coeff = arg.coeffs(i);
      if (not_lower_bounded) {
        if (max_sum - std::abs(coeff) <= rhs_domain.front().end) {
          if (coeff > 0) {
            // Fix the variable to 1 in the constraint and add it as enforcement
            // literal.
            rhs_domain = rhs_domain.AdditionWith(Domain(-coeff));
            ct->add_enforcement_literal(ref);
            // 'min_sum' remains unaffected.
            max_sum -= coeff;
          } else {
            // Fix the variable to 0 in the constraint and add its negation as
            // enforcement literal.
            ct->add_enforcement_literal(NegatedRef(ref));
            // 'max_sum' remains unaffected.
            min_sum -= coeff;
          }
          context->UpdateRuleStats(
              "linear: extracted enforcement literal from constraint");
          continue;
        }
      } else {
        DCHECK(not_upper_bounded);
        if (min_sum + std::abs(coeff) >= rhs_domain.back().start) {
          if (coeff > 0) {
            // Fix the variable to 0 in the constraint and add its negation as
            // enforcement literal.
            ct->add_enforcement_literal(NegatedRef(ref));
            // 'min_sum' remains unaffected.
            max_sum -= coeff;
          } else {
            // Fix the variable to 1 in the constraint and add it as enforcement
            // literal.
            rhs_domain = rhs_domain.AdditionWith(Domain(-coeff));
            ct->add_enforcement_literal(ref);
            // 'max_sum' remains unaffected.
            min_sum -= coeff;
          }
          context->UpdateRuleStats(
              "linear: extracted enforcement literal from constraint");
          continue;
        }
      }
    }

    // We keep this term.
    mutable_arg->set_vars(new_size, mutable_arg->vars(i));
    mutable_arg->set_coeffs(new_size, mutable_arg->coeffs(i));
    ++new_size;
  }

  mutable_arg->mutable_vars()->Truncate(new_size);
  mutable_arg->mutable_coeffs()->Truncate(new_size);
  FillDomainInProto(rhs_domain, mutable_arg);
}