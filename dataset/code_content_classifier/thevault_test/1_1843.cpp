void TransformIntoMaxCliques(PresolveContext* context) {
  if (context->is_unsat) return;

  auto convert = [](int ref) {
    if (RefIsPositive(ref)) return Literal(BooleanVariable(ref), true);
    return Literal(BooleanVariable(NegatedRef(ref)), false);
  };
  const int num_constraints = context->working_model->constraints_size();

  // Extract the bool_and and at_most_one constraints.
  std::vector<std::vector<Literal>> cliques;

  for (int c = 0; c < num_constraints; ++c) {
    ConstraintProto* ct = context->working_model->mutable_constraints(c);
    if (ct->constraint_case() == ConstraintProto::ConstraintCase::kAtMostOne) {
      std::vector<Literal> clique;
      for (const int ref : ct->at_most_one().literals()) {
        clique.push_back(convert(ref));
      }
      cliques.push_back(clique);
      if (RemoveConstraint(ct, context)) {
        context->UpdateConstraintVariableUsage(c);
      }
    } else if (ct->constraint_case() ==
               ConstraintProto::ConstraintCase::kBoolAnd) {
      if (ct->enforcement_literal().size() != 1) continue;
      const Literal enforcement = convert(ct->enforcement_literal(0));
      for (const int ref : ct->bool_and().literals()) {
        cliques.push_back({enforcement, convert(ref).Negated()});
      }
      if (RemoveConstraint(ct, context)) {
        context->UpdateConstraintVariableUsage(c);
      }
    }
  }

  const int old_cliques = cliques.size();

  // We reuse the max-clique code from sat.
  Model local_model;
  auto* graph = local_model.GetOrCreate<BinaryImplicationGraph>();
  const int num_variables = context->working_model->variables().size();
  graph->Resize(num_variables);
  for (const std::vector<Literal>& clique : cliques) {
    if (clique.size() <= 100) graph->AddAtMostOne(clique);
  }
  if (!graph->DetectEquivalences()) {
    context->is_unsat = true;
    return;
  }
  graph->TransformIntoMaxCliques(&cliques);

  // Add the Boolean variable equivalence detected by DetectEquivalences().
  // Those are needed because TransformIntoMaxCliques() will replace all
  // variable by its representative.
  for (int var = 0; var < num_variables; ++var) {
    const Literal l = Literal(BooleanVariable(var), true);
    if (graph->RepresentativeOf(l) != l) {
      const Literal r = graph->RepresentativeOf(l);
      context->StoreBooleanEqualityRelation(
          var, r.IsPositive() ? r.Variable().value()
                              : NegatedRef(r.Variable().value()));
    }
  }

  int new_cliques = 0;
  for (const std::vector<Literal>& clique : cliques) {
    if (clique.empty()) continue;
    new_cliques++;
    ConstraintProto* ct = context->working_model->add_constraints();
    for (const Literal literal : clique) {
      if (literal.IsPositive()) {
        ct->mutable_at_most_one()->add_literals(literal.Variable().value());
      } else {
        ct->mutable_at_most_one()->add_literals(
            NegatedRef(literal.Variable().value()));
      }
    }
  }
  context->UpdateNewConstraintsVariableUsage();
  VLOG(1) << "Merged " << old_cliques << " into " << new_cliques << " cliques";
}