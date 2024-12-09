void CostasSoft(const int dim) {
  Solver solver("Costas");

  // For the matrix and for the count of occurrences of each possible distance
  // for each stage
  const int num_elements = dim + (2 * dim + 1) * (dim);

  // create the variables
  std::vector<IntVar*> vars;
  solver.MakeIntVarArray(num_elements, -dim, dim, "var_", &vars);

  // the costas matrix
  std::vector<IntVar*> matrix(dim);
  // number of occurrences per stage
  std::vector<IntVar*> occurences;

  // All possible values of the distance vector
  // used to count the occurrence of all these values
  std::vector<int64> possible_values(2 * dim + 1);

  for (int64 i = -dim; i <= dim; ++i) {
    possible_values[i + dim] = i;
  }

  int index = 0;

  // Initialize the matrix that contains the coordinates of all '1' per row
  for (; index < dim; ++index) {
    matrix[index] = vars[index];
    vars[index]->SetMin(1);
  }

  // First constraint for the elements in the Costas Matrix. We want
  // them to be unique.
  std::vector<IntVar*> matrix_count;
  solver.MakeIntVarArray(2 * dim + 1, 0, dim, "matrix_count_", &matrix_count);
  solver.AddConstraint(
      solver.MakeDistribute(matrix, possible_values, matrix_count));

  // Here we only consider the elements from 1 to dim.
  for (int64 j = dim + 1; j <= 2 * dim; ++j) {
    // Penalize if an element occurs more than once.
    vars[index] =
        solver.MakeSemiContinuousExpr(solver.MakeSum(matrix_count[j], -1), 0, 1)
            ->Var();

    occurences.push_back(vars[index++]);
  }

  // Count the number of duplicates for each stage
  for (int i = 1; i < dim; ++i) {
    std::vector<IntVar*> subset(dim - i);

    // Initialize each stage
    for (int j = 0; j < dim - i; ++j) {
      IntVar* const diff = solver.MakeDifference(vars[j + i], vars[j])->Var();
      subset[j] = diff;
    }

    // Count the number of occurrences for all possible values
    std::vector<IntVar*> domain_count;
    solver.MakeIntVarArray(2 * dim + 1, 0, dim, "domain_count_", &domain_count);
    solver.AddConstraint(
        solver.MakeDistribute(subset, possible_values, domain_count));

    // Penalize occurrences of more than one
    for (int64 j = 0; j <= 2 * dim; ++j) {
      vars[index] = solver.MakeSemiContinuousExpr(
                              solver.MakeSum(domain_count[j], -1), 0, dim - i)
                        ->Var();

      occurences.push_back(vars[index++]);
    }
  }

  // We would like to minimize the penalties that we just computed
  IntVar* const objective_var = solver.MakeSum(occurences)->Var();
  OptimizeVar* const total_duplicates = solver.MakeMinimize(objective_var, 1);

  SearchMonitor* const log = solver.MakeSearchLog(1000, objective_var);

  // Out of all solutions, we just want to store the last one.
  SolutionCollector* const collector = solver.MakeLastSolutionCollector();
  collector->Add(vars);

  // The first solution that the local optimization is based on
  Evaluator evaluator(matrix);
  DecisionBuilder* const first_solution = solver.MakePhase(
      matrix,
      [&evaluator](int64 index) { return evaluator.VarEvaluator(index); },
      [&evaluator](int64 var, int64 value) {
        return evaluator.ValueEvaluator(var, value);
      });

  SearchLimit* const search_time_limit =
      solver.MakeLimit(FLAGS_timelimit, kint64max, kint64max, kint64max);

  // Locally optimize solutions for Lns
  SearchLimit* const fail_limit =
      solver.MakeLimit(kint64max, kint64max, FLAGS_sublimit, kint64max);

  DecisionBuilder* const subdecision_builder =
      solver.MakeSolveOnce(first_solution, fail_limit);

  std::vector<LocalSearchOperator*> localSearchOperators;

  // Apply RandomLns to free FLAGS_freevar variables at each stage
  localSearchOperators.push_back(
      solver.RevAlloc(new OrderedLns(matrix, FLAGS_freevar)));

  // Go through all possible permutations one by one
  localSearchOperators.push_back(
      solver.RevAlloc(new OrderedLns(matrix, FLAGS_freeorderedvar)));

  LocalSearchPhaseParameters* const ls_params =
      solver.MakeLocalSearchPhaseParameters(
          solver.ConcatenateOperators(localSearchOperators),
          subdecision_builder);

  DecisionBuilder* const second_phase =
      solver.MakeLocalSearchPhase(matrix, first_solution, ls_params);

  // Try to find a solution
  solver.Solve(second_phase, collector, log, total_duplicates,
               search_time_limit);

  if (collector->solution_count() > 0) {
    std::vector<int64> costas_matrix;
    std::string output;

    for (int n = 0; n < dim; ++n) {
      const int64 v = collector->Value(0, vars[n]);
      costas_matrix.push_back(v);
      StringAppendF(&output, "%3lld", v);
    }

    if (!CheckCostas(costas_matrix)) {
      LOG(INFO) << "No Costas Matrix found, closest solution displayed.";
    }

    LOG(INFO) << output;
  } else {
    LOG(INFO) << "No solution found";
  }
}