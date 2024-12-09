void AddOneTeamConstraints(Solver* const solver,
                           const std::vector<IntVar*>& opponents,
                           const std::vector<IntVar*>& home_aways,
                           const std::vector<IntVar*>& signed_opponents,
                           const IntTupleSet& home_away_tuples,
                           IntVar* const break_var, int num_teams) {
  const int half_season = num_teams - 1;

  // Each team meet all opponents once by half season.
  for (int half = 0; half <= 1; ++half) {
    for (int team_index = 0; team_index < num_teams; ++team_index) {
      std::vector<IntVar*> tmp_vars;
      for (int day = 0; day < half_season; ++day) {
        tmp_vars.push_back(opponents[half * half_season + day]);
      }
      solver->AddConstraint(solver->MakeAllDifferent(tmp_vars));
    }
  }

  // We meet each opponent once at home and once away per full season.
  for (int team_index = 0; team_index < num_teams; ++team_index) {
    solver->AddConstraint(solver->MakeAllDifferent(signed_opponents));
  }

  // Constraint per team on home_aways;
  for (int i = 0; i < num_teams; ++i) {
    std::vector<IntVar*> tmp_vars(home_aways);
    tmp_vars.push_back(break_var);
    solver->AddConstraint(
        solver->MakeAllowedAssignments(tmp_vars, home_away_tuples));
  }
}