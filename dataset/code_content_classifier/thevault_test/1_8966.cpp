void ComputeOneDayOneTeamTuples(int num_teams, IntTupleSet* const tuples) {
  for (int home_away = 0; home_away <= 1; ++home_away) {
    for (int opponent = 0; opponent < num_teams; ++opponent) {
      tuples->Insert3(opponent, home_away, opponent + home_away * num_teams);
    }
  }
}