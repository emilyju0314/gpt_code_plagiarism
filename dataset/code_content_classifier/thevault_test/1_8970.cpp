void SportsScheduling(int num_teams) {
  const int half_season = num_teams - 1;
  const int full_season = 2 * half_season;

  Solver solver("Sports Scheduling");

  // ----- Variables -----

  // The index of the opponent of a team on a given day.
  std::vector<std::vector<IntVar*> > opponents(num_teams);
  // The location of the match (home or away).
  std::vector<std::vector<IntVar*> > home_aways(num_teams);
  // Disambiguated version of the opponent variable incorporating the
  // home_away result.
  std::vector<std::vector<IntVar*> > signed_opponents(num_teams);
  for (int team_index = 0; team_index < num_teams; ++team_index) {
    solver.MakeIntVarArray(full_season, 0, num_teams - 1,
                           StringPrintf("opponent_%d_", team_index),
                           &opponents[team_index]);
    solver.MakeBoolVarArray(full_season,
                            StringPrintf("home_away_%d_", team_index),
                            &home_aways[team_index]);
    solver.MakeIntVarArray(full_season, 0, 2 * num_teams - 1,
                           StringPrintf("signed_opponent_%d", team_index),
                           &signed_opponents[team_index]);
  }
  // ----- Constraints -----

  // Constraints on a given day.
  IntTupleSet one_day_tuples(num_teams);
  ComputeOneDayTuples(num_teams, &one_day_tuples);
  for (int day = 0; day < full_season; ++day) {
    std::vector<IntVar*> all_vars;
    for (int i = 0; i < num_teams; ++i) {
      all_vars.push_back(signed_opponents[i][day]);
    }
    solver.AddConstraint(
        solver.MakeAllowedAssignments(all_vars, one_day_tuples));
  }

  // Links signed_opponents, home_away and opponents.
  IntTupleSet one_day_one_team_tuples(3);
  ComputeOneDayOneTeamTuples(num_teams, &one_day_one_team_tuples);
  for (int day = 0; day < full_season; ++day) {
    for (int team_index = 0; team_index < num_teams; ++team_index) {
      AddOneDayOneTeamConstraint(
          &solver, opponents[team_index][day], home_aways[team_index][day],
          signed_opponents[team_index][day], one_day_one_team_tuples);
    }
  }

  // Constraints on a team.
  IntTupleSet home_away_tuples(full_season + 1);
  ComputeOneTeamHomeAwayTuples(num_teams, &home_away_tuples);
  std::vector<IntVar*> team_breaks;
  solver.MakeIntVarArray(num_teams, 0, full_season, "team_break_",
                         &team_breaks);
  for (int team = 0; team < num_teams; ++team) {
    AddOneTeamConstraints(&solver, opponents[team], home_aways[team],
                          signed_opponents[team], home_away_tuples,
                          team_breaks[team], num_teams);
  }

  // ----- Search -----

  std::vector<SearchMonitor*> monitors;

  // Objective.
  IntVar* const objective_var =
      solver.MakeSum(team_breaks)->VarWithName("SumOfBreaks");
  OptimizeVar* const objective_monitor = solver.MakeMinimize(objective_var, 1);
  monitors.push_back(objective_monitor);

  // Store all variables in a single array.
  std::vector<IntVar*> all_signed_opponents;
  for (int team_index = 0; team_index < num_teams; ++team_index) {
    for (int day = 0; day < full_season; ++day) {
      all_signed_opponents.push_back(signed_opponents[team_index][day]);
    }
  }

  // Build default phase decision builder.
  DefaultPhaseParameters parameters;
  parameters.run_all_heuristics = FLAGS_run_all_heuristics;
  parameters.heuristic_period = FLAGS_heuristics_period;
  parameters.restart_log_size = FLAGS_restart_log_size;
  DecisionBuilder* const db =
      solver.MakeDefaultPhase(all_signed_opponents, parameters);

  // Search log.
  SearchMonitor* const log = solver.MakeSearchLog(1000000, objective_monitor);
  monitors.push_back(log);

  // Search limit.
  SearchLimit* const limit = solver.MakeTimeLimit(FLAGS_time_limit);
  monitors.push_back(limit);

  // Solution collector.
  SolutionCollector* const collector = solver.MakeLastSolutionCollector();
  for (int team_index = 0; team_index < num_teams; ++team_index) {
    collector->Add(opponents[team_index]);
    collector->Add(home_aways[team_index]);
  }
  monitors.push_back(collector);

  // And search.
  solver.Solve(db, monitors);

  // Display solution.
  if (collector->solution_count() == 1) {
    LOG(INFO) << "Solution found in " << solver.wall_time() << " ms, and "
              << solver.failures() << " failures.";
    for (int team_index = 0; team_index < num_teams; ++team_index) {
      std::string line;
      for (int day = 0; day < full_season; ++day) {
        const int opponent = collector->Value(0, opponents[team_index][day]);
        const int home_away = collector->Value(0, home_aways[team_index][day]);
        line += StringPrintf("%2d%s ", opponent, home_away ? "@" : " ");
      }
      LOG(INFO) << line;
    }
  }
}