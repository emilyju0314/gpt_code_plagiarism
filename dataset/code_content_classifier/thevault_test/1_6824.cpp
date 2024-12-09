void TBrateLimitor::adjustScore(int score) {
  // pay the penalty
  if (last_token_rate > token_rate)
    n_score += score;
  else
    p_score += score;
}