void ComputeOneDayTuples(int num_teams, IntTupleSet* const day_tuples) {
  LOG(INFO) << "Compute possible opponents and locations for any day.";
  Solver solver("ComputeOneDayTuples");

  // We create the variables.
  std::vector<IntVar*> opponents;
  std::vector<IntVar*> home_aways;
  std::vector<IntVar*> signed_opponents;
  solver.MakeIntVarArray(num_teams, 0, num_teams - 1, "opponent_", &opponents);
  solver.MakeBoolVarArray(num_teams, "home_away_", &home_aways);
  solver.MakeIntVarArray(num_teams, 0, 2 * num_teams - 1, "signed_opponent_",
                         &signed_opponents);

  // All Diff constraint.
  solver.AddConstraint(solver.MakeAllDifferent(opponents));

  // Cannot play against itself
  for (int i = 0; i < num_teams; ++i) {
    solver.AddConstraint(solver.MakeNonEquality(opponents[i], i));
  }

  // Matching constraint (vars[i] == j <=> vars[j] == i).
  for (int i = 0; i < num_teams; ++i) {
    for (int j = 0; j < num_teams; ++j) {
      if (i != j) {
        solver.AddConstraint(
            solver.MakeEquality(solver.MakeIsEqualCstVar(opponents[i], j),
                                solver.MakeIsEqualCstVar(opponents[j], i)));
      }
    }
  }

  // num_teams/2 teams are home.
  solver.AddConstraint(solver.MakeSumEquality(home_aways, num_teams / 2));

  // Link signed_opponents, home_away and opponents
  IntTupleSet one_day_one_team_tuples(3);
  ComputeOneDayOneTeamTuples(num_teams, &one_day_one_team_tuples);
  for (int team_index = 0; team_index < num_teams; ++team_index) {
    std::vector<IntVar*> tmp_vars;
    tmp_vars.push_back(opponents[team_index]);
    tmp_vars.push_back(home_aways[team_index]);
    tmp_vars.push_back(signed_opponents[team_index]);
    solver.AddConstraint(
        solver.MakeAllowedAssignments(tmp_vars, one_day_one_team_tuples));
  }

  // if A meets B at home, B meets A away.
  for (int first_team = 0; first_team < num_teams; ++first_team) {
    IntVar* const first_home_away = home_aways[first_team];
    IntVar* const second_home_away =
        solver.MakeElement(home_aways, opponents[first_team])->Var();
    IntVar* const reverse_second_home_away =
        solver.MakeDifference(1, second_home_away)->Var();
    solver.AddConstraint(
        solver.MakeEquality(first_home_away, reverse_second_home_away));
  }

  // Search for solutions and fill day_tuples.
  DecisionBuilder* const db = solver.MakePhase(
      signed_opponents, Solver::CHOOSE_FIRST_UNBOUND, Solver::ASSIGN_MIN_VALUE);
  solver.NewSearch(db);
  while (solver.NextSolution()) {
    std::vector<int> solution;
    for (int i = 0; i < num_teams; ++i) {
      solution.push_back(signed_opponents[i]->Value());
    }
    day_tuples->Insert(solution);
  }
  solver.EndSearch();
  LOG(INFO) << day_tuples->NumTuples()
            << " solutions to the one-day matching problem";
}