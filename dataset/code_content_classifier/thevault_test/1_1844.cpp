std::vector<int> GetLiteralsFromSetPPCConstraint(ConstraintProto* ct) {
  std::vector<int> sorted_literals;
  if (ct->constraint_case() == ConstraintProto::ConstraintCase::kAtMostOne) {
    for (const int literal : ct->at_most_one().literals()) {
      sorted_literals.push_back(literal);
    }
  } else if (ct->constraint_case() ==
             ConstraintProto::ConstraintCase::kBoolOr) {
    for (const int literal : ct->bool_or().literals()) {
      sorted_literals.push_back(literal);
    }
  }
  std::sort(sorted_literals.begin(), sorted_literals.end());
  return sorted_literals;
}