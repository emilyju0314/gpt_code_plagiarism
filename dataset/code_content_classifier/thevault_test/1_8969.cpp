void ComputeOneTeamHomeAwayTuples(int num_teams,
                                  IntTupleSet* const home_away_tuples) {
  LOG(INFO) << "Compute possible sequence of home and aways for any team.";
  const int half_season = num_teams - 1;
  const int full_season = 2 * half_season;

  Solver solver("compute_home_aways");
  std::vector<IntVar*> home_aways;
  solver.MakeBoolVarArray(full_season, "home_away_", &home_aways);
  for (int day = 0; day < full_season - 2; ++day) {
    std::vector<IntVar*> tmp_vars;
    tmp_vars.push_back(home_aways[day]);
    tmp_vars.push_back(home_aways[day + 1]);
    tmp_vars.push_back(home_aways[day + 2]);
    IntVar* const partial_sum = solver.MakeSum(tmp_vars)->Var();
    solver.AddConstraint(solver.MakeBetweenCt(partial_sum, 1, 2));
  }
  DecisionBuilder* const db = solver.MakePhase(
      home_aways, Solver::CHOOSE_FIRST_UNBOUND, Solver::ASSIGN_MIN_VALUE);
  solver.NewSearch(db);
  while (solver.NextSolution()) {
    std::vector<int> solution;
    for (int i = 0; i < full_season; ++i) {
      solution.push_back(home_aways[i]->Value());
    }
    int breaks = 0;
    for (int i = 0; i < full_season - 1; ++i) {
      breaks += (solution[i] == solution[i + 1]);
    }
    solution.push_back(breaks);
    home_away_tuples->Insert(solution);
  }
  solver.EndSearch();
  LOG(INFO) << home_away_tuples->NumTuples()
            << " combination of home_aways for a team on the full season";
}