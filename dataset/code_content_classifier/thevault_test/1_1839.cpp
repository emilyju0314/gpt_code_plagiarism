bool PresolveContext::VariableIsUniqueAndRemovable(int ref) const {
  return var_to_constraints[PositiveRef(ref)].size() == 1 &&
         affine_relations.ClassSize(PositiveRef(ref)) == 1 &&
         !enumerate_all_solutions;
}