bool ProcessSetPPCSubset(int c1, int c2, const std::vector<int>& c2_minus_c1,
                         const std::vector<int>& original_constraint_index,
                         std::vector<bool>* marked_for_removal,
                         PresolveContext* context) {
  CHECK(!(*marked_for_removal)[c1]);
  CHECK(!(*marked_for_removal)[c2]);
  ConstraintProto* ct1 = context->working_model->mutable_constraints(
      original_constraint_index[c1]);
  ConstraintProto* ct2 = context->working_model->mutable_constraints(
      original_constraint_index[c2]);
  if (ct1->constraint_case() == ConstraintProto::ConstraintCase::kBoolOr &&
      ct2->constraint_case() == ConstraintProto::ConstraintCase::kAtMostOne) {
    // fix extras in c2 to 0
    for (const int literal : c2_minus_c1) {
      context->SetLiteralToFalse(literal);
      context->UpdateRuleStats("setppc: fixed variables");
    }
    return true;
  }
  if (ct1->constraint_case() == ct2->constraint_case()) {
    if (ct1->constraint_case() == ConstraintProto::ConstraintCase::kBoolOr) {
      (*marked_for_removal)[c2] = true;
      context->UpdateRuleStats("setppc: removed dominated constraints");
      return false;
    }
    CHECK_EQ(ct1->constraint_case(),
             ConstraintProto::ConstraintCase::kAtMostOne);
    (*marked_for_removal)[c1] = true;
    context->UpdateRuleStats("setppc: removed dominated constraints");
    return false;
  }
  return false;
}